#ifndef RESPONSE_H
#define RESPONSE_H

#include <json.hpp>

#define SIGNATURE_SIZE 2

class Response {

private:

	int ID;
	std::time_t time_received;
	
	const std::string signatures[SIGNATURE_SIZE] = {"login", "logout"};

	json j;

public:

	//function pointer can be used for things like loading screen.
	void wait_response(char * response, int server_socket, int timeout, void * fptr);
	void wait_response(char * response, int server_socket, int timeout);
	void wait_response(char * response, int server_socket);

	void buff_json(char * data, json j);

};
#endif