#include <random>
#include <string>
#include <iostream>
#include <climits>

#include "request.h"

std::string Request::get_signature(Request::REQUESTS request_type){
	return signatures[request_type];
}

void Request::set_request_data(std::string data){

	//DO CHECKING LATER
	this->request = data;
}

int Request::create_request_id(){

	std::random_device rseed;
	std::mt19937 rgen(rseed()); // mersenne_twister
	std::uniform_int_distribution<int> distribution(0, INT_MAX); //inclusive

	this->ID = distribution(rgen);

	return this->ID;
}