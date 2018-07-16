#ifndef LOGIN_REQUEST_H
#define LOGIN_REQUEST_H

#include <string>

#include "request.h"

class LoginRequest : public Request {

private:

	std::string encrypted_username; // "username password"
	std::string encrypted_password; // "username password"

public:

	int set_username(std::string username);
	int set_password(std::string password);

	int package_request();

	int send_login_request();
	int react_response();

	void print_request();

};
#endif