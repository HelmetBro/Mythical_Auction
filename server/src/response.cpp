#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "response.h"

//helper
// std::vector<std::string> split_data(const std::string &s, char delim) {
//     std::vector<std::string> parts;
//     std::stringstream ss(s);
//     std::string element;

//     while(std::getline(ss, element, delim))
//         parts.push_back(element);

//     return parts;
// }

//0 = success, anything else is fail
int Response::handle_request(){
	/* Parse request data.
		Always going to be request ID;type;etc.
	*/


	//FIGURE OUT HOW TO FORMAT DATA IN REQUEST

	// std::vector<std::string> data = split_data(this->request_data, this->DELIMITER[0]);

	this->request_id = stoi(data.at(0)); //setting request ID
	this->request_type = (std::string) data.at(1); //setting request ID












	//std::stoi(





    // std::cout << "SERVER CLIENT SOCKET: " << this->client_socket << std::endl;
    return 0;
}

void Response::print_response(){

	char buffer[26];
	struct tm tstruct;
	tstruct = *std::localtime(&(this->time_received));
	strftime(buffer, sizeof buffer, "%Y-%m-%d %H:%M:%S", &tstruct);


	std::cout << "Response > client_socket: " << this->client_socket << std::endl
			  << "		   > request_id: " << this->request_id << std::endl
			  << "		   > request_type: " << this->request_type << std::endl
			  << "		   > request_data: " << this->request_data << std::endl
			  << "		   > time_received: " << buffer << std::endl;
}