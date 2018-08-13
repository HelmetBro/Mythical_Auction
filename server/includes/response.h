#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <ctime>

#define SIGNATURE_SIZE 2

class Response{

private:
	const std::string signatures[SIGNATURE_SIZE] = {"login", "logout"};

	int request_id;
	std::string request_type;
	std::string response;

public:

	const char DELIMITER = ';';
	int client_socket;

	std::string request_data;

	enum REQUESTS {LOGIN, LOGOUT};

	std::time_t time_received;
	std::string time_request_sent;
	std::time_t time_response_sent;

	int handle_login(char * data);
	int handle_logout();
	int manage_request_chain(char * data);

	int interpret(char * data);
	int log_to_database();
	int formulate_response();
	int send_response();

	int find_request_type();

	void print_response();

};
#endif