#include <string.h>
#include <iostream>
#include <ctime>
#include <unistd.h>

#include "login_request.h"

int LoginRequest::set_username(std::string username){
	//later, encrypt
	this->encrypted_username = username;
	return 0; //success
}

int LoginRequest::set_password(std::string password){
	//later, encrypt
	this->encrypted_password = password;
	return 0; //success
}

//username, and password
int LoginRequest::package_request(){

	package_request_header(LOGIN);

	this->request.append(this->encrypted_username); //USERNAME
	this->request.append(&DELIMITER);
	this->request.append(this->encrypted_password); //PASSWORD

	return 0;
}

int LoginRequest::send_login_request(int server_socket){
	std::cout << this->request << std::endl;
	if(write(server_socket, this->request.c_str(), request.length() + 1) < 0)
            std::cout << "WRITE ERROR FROM CLIENT";

    return 0;
}

int LoginRequest::react_response(){
	
}


void LoginRequest::print_request(){

	std::cout << "REQUEST > ID: " << this->ID << std::endl 
			  << "        > data: " << this->request << std::endl;
}