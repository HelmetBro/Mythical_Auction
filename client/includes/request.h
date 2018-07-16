#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <ctime>

class Request{

protected:

	int ID;
	const std::string DELIMITER = ";";
	const std::string signatures[1] = {"login"};

	std::time_t time_sent;
	std::string request;

public:

	enum REQUESTS {LOGIN};
	std::string get_signature(Request::REQUESTS request_type);

	int create_request_id();
	void set_request_data(std::string data);
	virtual void print_request() = 0;

};
#endif