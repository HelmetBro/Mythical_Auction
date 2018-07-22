#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <ctime>

#define SIGNATURE_SIZE 1

class Request{

protected:

	int ID;
	const char DELIMITER = ';';
	const std::string signatures[SIGNATURE_SIZE] = {"login"};

	std::time_t time_sent;
	std::string request;

public:

	enum REQUESTS {LOGIN};
	std::string get_signature(Request::REQUESTS request_type);

	int create_request_id();

	void package_request_header(Request::REQUESTS);

	virtual void print_request() = 0;
};
#endif