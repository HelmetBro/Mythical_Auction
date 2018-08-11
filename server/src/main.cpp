#include <sys/types.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include <ctime>
#include <iostream>

#include "response.h"


#define BACKLOG 100 // if more than BACKLOG clients in the server accept queue, client connect will fail
#define TIMEOUT 5

const char * const IP_ADDRESS = "192.168.0.117";
const short PORT = 51992;



// void error(char *msg)
// {
//     fprintf(stderr, "ERROR: %s failed\n", msg);
//     exit(-1);
// }

struct sockaddr_in make_server_addr(short port){
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    return addr;
}

int create_server_socket(short port){
    int s = socket(AF_INET, SOCK_STREAM, 0);
    int optval = 1;
    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
    struct sockaddr_in my_addr = make_server_addr(port);
    if ( s == -1 )
        std::cout << "SERVER SOCKET ERROR";
    bind(s, (struct sockaddr*)&my_addr, sizeof my_addr);
    listen(s, BACKLOG);
    return s;
}

void get_request_from_socket(Response * response, char * data){
    int n = read(response->client_socket, data, BUFSIZ);
    
    /*
    If there are 0 or less, the client either disconnected or
    manage to send a corrupted request. this terminates the
    thread so the whole server doesnt go down.
    */
    if (n <= 0)
        pthread_exit(NULL);
    
    data[n] = '\0';
}

// void write_file_to_client_socket(char *file, int socket)
// {
//     char buf[BUFSIZ];
//     int n;
//     int ifd = open(file, O_RDONLY);
//     if ( ifd == -1 )
//         error("open()");
//     while ( (n = read(ifd, buf, BUFSIZ)) > 0 )
//         write(socket, buf, n);
//     close(ifd);
// }

// void time_out(int sig, siginfo_t *si, void *context){

//     pthread_t thread_id = pthread_self();
//     std::cout << "ID: " << thread_id << std::endl;
//     fprintf(stderr, "Request timed out.\n");
//     exit(0);
// }

// void set_time_out(int seconds){

//     //creating timer
//     struct itimerval value = {0};
//     value.it_value.tv_sec = seconds;
//     setitimer(ITIMER_REAL, &value, NULL);

//     pthread_t thread_id = pthread_self();

//     // signal(SIGALRM, time_out);
//     //creating signal
//     struct sigaction tah;
//     memset(&tah, 0, sizeof tah);
//     tah.sa_flags = SA_SIGINFO;
//     // tah.sa_handler = time_out;
//     tah.sa_sigaction = time_out;
    

//     sigaction(SIGALRM, &tah, NULL);
// }

void * thread_work(void * arg){
    Response * response = (Response *) arg;
    
    char data[BUFSIZ];
    get_request_from_socket(response, data);

    response->handle_login(data);
    response->manage_request_chain(data);

    //ONLY DO THIS ONCE CLIENT DISCONNECTS
    std::cout << "DISCONNECTED!" << std::endl;
    close(response->client_socket);
    delete response;
    pthread_exit(0);
}

void accept_client_requests(int server_socket){
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t sin_size = sizeof client_addr;

    while ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &sin_size)) > 0)
    {

        std::cout << "SOCKET: " << client_socket << std::endl;
        //add to thread-safe list of online clients

        Response * response = new Response();
        response->client_socket = client_socket;
        response->time_received = std::time(0);

        pthread_t p;
        pthread_create(&p, NULL, thread_work, (void *)response);
        //Note: later handle timeout from the parent thread. Unique information cannot be sent through signlas
    }

}

int main(int argc, char *argv[]){

    int server_socket = create_server_socket(PORT);
    accept_client_requests(server_socket);
    // shutdown(server_socket, 2);
    return 0;
}