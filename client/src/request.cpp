#include <random>
#include <string>
#include <iostream>
#include <climits>
#include <ctime>

#include "request.h"

std::string Request::get_signature(Request::REQUESTS request_type){
	return signatures[request_type];
}

int Request::create_request_id(){

	std::random_device rseed;
	std::mt19937 rgen(rseed()); // mersenne_twister
	std::uniform_int_distribution<int> distribution(0, INT_MAX); //inclusive

	this->ID = distribution(rgen);

	return this->ID;
}

//time sent;ID number;request type;
void Request::package_request_header(Request::REQUESTS request_type){

	this->ID = create_request_id();
	this->time_sent = std::time(0);

	//get time
	char time_buffer[26];
	struct tm tstruct;
	tstruct = *std::localtime(&(this->time_sent));
	strftime(time_buffer, sizeof time_buffer, "%Y-%m-%d %H:%M:%S", &tstruct);
	std::string data = time_buffer;
	
	//pack on information to data
	data.append(&DELIMITER);	
	data.append(std::to_string(this->ID)); //ID
	data.append(&DELIMITER);
	data.append(this->get_signature(request_type)); //SIGNATURE
	data.append(&DELIMITER);

	this->request = data;
}