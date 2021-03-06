#include <ncurses.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "login.h"

#define MAX_INPUT_CHAR 50

//helper
struct sockaddr_in make_server_addr(const char * const host, short port){
    struct sockaddr_in addr;
    bzero(&addr, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    return addr;
}

int Login::establish_connection(const char * const host, short port){
	struct sockaddr_in addr = make_server_addr(host, port);
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if(server_socket < 0)
		printw("ERROR IN SOCKET");

	if(connect(server_socket, (struct sockaddr*)&addr, sizeof addr) < 0){
		printw("ERROR IN STATUS");
		refresh();
		endwin();
		exit(-1);
	}

	printw("CONNECTED!\n");
	refresh();
	
	return server_socket; //use this to read and write
}

void Login::print_login(){

	char msg[]="----THIS IS THE LOGIN IMAGE----\n";
	int row, col;
	getmaxyx(stdscr,row,col);
	mvprintw(row/2 - 5,(col-strlen(msg))/2,"%s",msg);

	refresh();
}

void Login::print_username_prompt(){
	printw("Enter username: ");
	refresh();
}
void Login::print_password_prompt(){
	printw("Enter password: ");
	refresh();
}

void Login::clear(){
	this->l_request.clear_credentials();
	this->l_request.clear_data();
} 

int Login::get_username(){
	echo();
	char username[MAX_INPUT_CHAR];
	bzero(username, MAX_INPUT_CHAR);
	getnstr(username, MAX_INPUT_CHAR);
	noecho();
	return l_request.set_username(std::string(username));
}
int Login::get_password(){
	char password[MAX_INPUT_CHAR];
	bzero(password, MAX_INPUT_CHAR);
	getnstr(password, MAX_INPUT_CHAR);
	return l_request.set_password(std::string(password));
}

int Login::authenticate(int server_socket){
	this->l_request.package_request();
	this->l_request.send_request(server_socket);

	char data[BUFSIZ];
	this->l_response.wait_response(data, server_socket);

	return this->l_response.determine_response();
}