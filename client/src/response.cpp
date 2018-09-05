// #include <string>
// #include <iostream>
// #include <climits>
// #include <ctime>
// #include <unistd.h>
#include <json.hpp>

using json = nlohmann::json;

#include "response.h"

void Response::wait_response(char * response, int server_socket, int timeout, void * fptr){
	// char data[BUFSIZ];
	// int n = read(server_socket, data, BUFSIZ);
 //    if (n < 0)
 //        std::cout << "CLIENT RECEIVE_RESPONSE READ ERROR";
 //    data[n] = '\0';

 //    this->response = data;
}
void Response::wait_response(char * response, int server_socket, int timeout){
	Response::wait_response(response, server_socket, timeout, NULL);
}
void Response::wait_response(char * response, int server_socket){
	Response::wait_response(response, server_socket, 0, NULL);
}

void Response::buff_json(char * data, json j){

}