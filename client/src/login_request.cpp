#include <string.h>
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

//username, and password
int LoginRequest::package_request(){

	package_request_header(LOGIN);

	this->j["username"] = this->encrypted_username;
	this->j["password"] = this->encrypted_password;

	return 0;
}

int LoginRequest::react_response(){
	
	//use ID and response to get the string (authenticate)

	// if(this->response == "valid"){
	// 	return 0; // 0 is VALID
	// }

	//return an error code here! 
}

void LoginRequest::clear_credentials(){
	this->encrypted_username.clear();
	this->encrypted_password.clear();
}

void LoginRequest::print_request(){

	std::cout << "REQUEST > ID: " << this->ID << std::endl 
			  << "data:\n" << this->j.dump(4) << std::endl;
}