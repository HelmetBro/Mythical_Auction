#include <random>
#include <string>
#include <iostream>
#include <climits>
#include <ctime>
#include <unistd.h>

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
	
	this->j["ID"] = this->ID;
	this->j["time_sent"] = time_buffer;

}

int Request::send_request(int server_socket){
	//error check if request is nothing or null, throw an error!
	if(write(server_socket, this->j.dump().c_str(), this->j.size()) < 0)
            std::cout << "WRITE ERROR FROM CLIENT";

    return 0;
}

void Request::clear_data(){
	this->ID = 0;
	this->j.clear();
}