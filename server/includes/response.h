#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <ctime>

#define SIGNATURE_SIZE 1

class Response{

private:
	const std::string signatures[SIGNATURE_SIZE] = {"login"};
	std::string response;

public:

	const char DELIMITER = ';';
	int client_socket;

	int request_id;
	std::string request_type;

	enum REQUESTS {LOGIN};

	std::time_t time_received;
	std::string time_request_sent;
	std::time_t time_response_sent;

	//helper
	int find_string_index();

	int interpret(char * data);
	int log_to_database();
	int formulate_response();
	int send_response();
	void print_response();

};
#endif