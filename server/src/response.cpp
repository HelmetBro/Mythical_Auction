#include <iostream>
#include <string.h>
#include <unistd.h>

#include "response.h"

//0 = success, anything else is fail
int Response::interpret(char * data){
	/* Parse request data.
		Always going to be: time;ID;type;etc.
	*/

	std::cout << data << std::endl;

	//setting time when request was sent
	char * token = strtok(data, &this->DELIMITER);
	if(token == NULL)
		std::cout << "HOUSTON, WE GOT A PROBLEM...";
	this->time_request_sent = token; 

	token = strtok(NULL, &this->DELIMITER);
	if(token == NULL)
		std::cout << "HOUSTON, YOU GOTTA TAKE A LOOK AT THIS-";
	this->request_id = atoi(token + 1); //temporary fix, first char is a '\0' I think
	
	//setting request type
	token = strtok(NULL, &this->DELIMITER);
	if(token == NULL)
		std::cout << "HOUSTON, WHAT IN THE HELL IS GOING ON?!";
	this->request_type = token + 1;

    // std::cout << "SERVER CLIENT SOCKET: " << this->client_socket << std::endl;
    return 0;
}


int Response::log_to_database(){
	std::cout << "LOG TO DATABASE FINISH LATER" << std::endl;
	return 0;
}


//helper to handle_request
int Response::find_string_index(){

	//do more intense checking here?
	int index = 0;
	for(; index < SIGNATURE_SIZE; index++)
		if(this->request_type.compare(signatures[index]) == 0)
			break;

	return index;
}

//the big switch statement
int Response::formulate_response(){

	switch(find_string_index()){
		case LOGIN:

			//handle - response stored in "response" variable
			/*
			to prevent attacks, use the unique ID send to encrypt "valid"
			or "invalid" when sent to the client. have the client decrypt with
			knowing their ID. This can be used as the key.
			*/
			this->response = "invalid";

			break;

		default:
			//UH-OH, BOYS
			break;
	}

	//log response to data base
	std::cout << "LOG RESPONSE TO DATABASE LATER" << std::endl;

	return 0;
}


int Response::send_response(){
	std::cout << this->response << std::endl;
	if(write(client_socket, this->response.c_str(), response.length() + 1) < 0)
            std::cout << "WRITE ERROR FROM CLIENT";

    return 0;
}

void Response::print_response(){

	char buffer[26];
	struct tm tstruct;
	tstruct = *std::localtime(&(this->time_received));
	strftime(buffer, sizeof buffer, "%Y-%m-%d %H:%M:%S", &tstruct);

	std::cout << "Response > client_socket: " << this->client_socket << std::endl
			  << "         > request_id: " << this->request_id << std::endl
			  << "         > request_type: " << this->request_type << std::endl
			  << "         > time_request_sent: " << this->time_request_sent << std::endl
			  << "         > time_received: " << buffer << std::endl;
}