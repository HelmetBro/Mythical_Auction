#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <ctime>

class Response{

private:
	const std::string signatures[1] = {"login"};

public:

	int client_socket;
	std::string request_data;

	enum REQUESTS {LOGIN};

	std::time_t time_received;
	std::time_t time_sent;

	int handle_request();

};
#endif