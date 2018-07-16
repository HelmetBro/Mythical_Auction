#include <string>
#include <iostream>

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

int LoginRequest::package_request(){

	this->ID = create_request_id();

	//ID number, request type, username, and password
	

	std::string data;
	//generate ID number

	data = std::to_string(this->ID);
	data.append(DELIMITER);
	data.append(this->get_signature(LOGIN));
	data.append(DELIMITER);
	data.append(this->encrypted_username);
	data.append(DELIMITER);
	data.append(this->encrypted_password);

	set_request_data(data);

	return 0;
}

int LoginRequest::send_login_request(){
	
}

int LoginRequest::react_response(){
	
}


void LoginRequest::print_request(){

	std::cout << "REQUEST > ID: " << ID << std::endl 
			  << "        > data: " << request << std::endl;
}