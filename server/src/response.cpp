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
	this->request_id = atoi(token);
	
	//setting request type
	token = strtok(NULL, &this->DELIMITER);
	if(token == NULL)
		std::cout << "HOUSTON, WHAT IN THE HELL IS GOING ON?!";
	this->request_type = token;

    bzero(data, BUFSIZ);
    return 0;
}


int Response::log_to_database(){
	std::cout << "LOG TO DATABASE FINISH LATER" << std::endl;
	//MAKE SURE I USE A MUTEX!!!!!
	return 0;
}


//returns type of request in enum form
int Response::find_request_type(){

	//do more intense checking here?
	int index = 0;
	for(; index < SIGNATURE_SIZE; index++)
		if(this->request_type.compare(signatures[index]) == 0)
			break;

	return index;
}

//the big switch statement
int Response::formulate_response(){

	switch(find_request_type()){
		case LOGIN:

			//handle - response stored in "response" variable
			/*
			to prevent attacks, use the unique ID send to encrypt "valid"
			or "invalid" when sent to the client. have the client decrypt with
			knowing their ID. This can be used as the key.
			*/
			this->response = "valid";

			break;

		default:
			//UH-OH, BOYS
			break;
	}

	//log response to data base
	this->log_to_database();

	return 0;
}


int Response::send_response(){
	std::cout << this->response << std::endl;
	if(write(client_socket, this->response.c_str(), response.length() + 1) < 0)
            std::cout << "WRITE ERROR FROM CLIENT";

    return 0;
}

int Response::handle_login(char * data){
	this->interpret(data);
    this->print_response();
    this->log_to_database();

    //ensure that first response is always a login request
    if(this->find_request_type() != Response::LOGIN)
        std::cout << "HACKER HACKER HACKER!" << std::endl;

    this->formulate_response();
    this->send_response();

    return 0;
}

int Response::handle_logout(){
	return 0;
}

int Response::manage_request_chain(char * data){

	int num_characters = 1; // equals 1 just to start while loop
    while((num_characters = read(this->client_socket, data, BUFSIZ)) > 0){

    	//just a little bounds checking
    	data[num_characters] = '\0';
        
        this->interpret(data);
        this->print_response();
        this->log_to_database();

        if(this->find_request_type() == Response::LOGOUT)
            this->handle_logout();

        this->formulate_response();
        this->send_response();

    }
    
    if(num_characters < 0)
        std::cout << "ERROR! SERVER INVALID READ" << std::endl;

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