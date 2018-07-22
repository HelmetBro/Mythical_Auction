#include <iostream>
#include <string.h>

#include "response.h"

//0 = success, anything else is fail
int Response::interpret(char * data){
	/* Parse request data.
		Always going to be: time;ID;type;etc.
	*/

	//setting time when request was sent
	char * token = strtok(data, &this->DELIMITER);
	if(token == NULL)
		std::cout << "HOUSTON, WE GOT A PROBLEM...";
	this->time_request_sent = token; 

	if(token == NULL)
		std::cout << "HOUSTON, YOU GOTTA TAKE A LOOK AT THIS-";
	this->request_id = atoi(token + 1); //temporary fix, first char is a '\0' I think
	
	//setting request type
	token = strtok(NULL, &this->DELIMITER);
	if(token == NULL)
		std::cout << "HOUSTON, WHAT IN THE HELL IS GOING ON?!";
	this->request_type = token;

    // std::cout << "SERVER CLIENT SOCKET: " << this->client_socket << std::endl;
    return 0;
}


int Response::log_to_database(){
	std::cout << "LOG TO DATABASE FINISH LATER" << std::endl;
	return 0;
}


//the big switch statement
int Response::handle_request(){

	// switch(){

	// }





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