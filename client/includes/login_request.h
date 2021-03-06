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

	void clear_credentials();

	int package_request();
	int react_response(); // should be in login
	void print_request();

};
#endif