#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <ctime>
#include <json.hpp>

#define SIGNATURE_SIZE 2

using json = nlohmann::json;

class Request{

protected:

	int ID;
	std::time_t time_sent;
	
	const std::string signatures[SIGNATURE_SIZE] = {"login", "logout"};

	json j;

public:

	enum REQUESTS {LOGIN, LOGOUT};
	std::string get_signature(Request::REQUESTS request_type);

	int create_request_id();
	void package_request_header(Request::REQUESTS);

	virtual void print_request() = 0;

	int send_request(int server_socket);
	// int receive_response(int server_socket);

	void clear_data();
};
#endif

