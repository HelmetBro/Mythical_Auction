#include <iostream>
#include <string>
#include <strings.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "login.h"


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
		std::cout << "ERROR IN SOCKET";

	if(connect(server_socket, (struct sockaddr*)&addr, sizeof addr) < 0){
		std::cout << "ERROR IN STATUS";
		exit(-1);
	}

	std::cout << "CONNECTED!" << std::endl;

	return server_socket; //use this to read and write
}

void Login::print_login(){
	std::cout << "THIS IS THE LOGIN IMAGE" << std::endl;
}

void Login::print_username_prompt(){
	std::cout << "Enter username: " << std::endl;
}
void Login::print_password_prompt(){
	std::cout << "Enter password: " << std::endl;
}

void Login::clear(){
	this->l_request.clear_credentials();
	this->l_request.clear_data();
} 

int Login::get_username(){
	std::string username = "pepe";
	return l_request.set_username(username);
}
int Login::get_password(){
	std::string password = "trump";
	return l_request.set_password(password);
}

int Login::authenticate(int server_socket){

	this->l_request.package_request();
	this->l_request.print_request();
	this->l_request.send_request(server_socket);
	this->l_request.receive_response(server_socket);

	return this->l_request.react_response();;
}