#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <ctime>

#define SIGNATURE_SIZE 2

class Request{

protected:

	int ID;
	const std::string signatures[SIGNATURE_SIZE] = {"login", "logout"};

	std::time_t time_sent;
	std::string request;
	std::string response;

public:

	static const char DELIMITER;

	enum REQUESTS {LOGIN, LOGOUT};
	std::string get_signature(Request::REQUESTS request_type);

	int create_request_id();
	void package_request_header(Request::REQUESTS);

	virtual void print_request() = 0;

	int send_request(int server_socket);
	int receive_response(int server_socket);

	void clear_data();
};
#endif

