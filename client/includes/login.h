#ifndef LOGIN_H
#define LOGIN_H

#include "login_request.h"
#include "login_response.h"

class Login {

private:

	LoginRequest l_request;
	LoginResponse l_response;

public:

	int establish_connection(const char * const host, short port);

	void print_login();
	void print_username_prompt();
	void print_password_prompt();

	void clear();

	int get_username();
	int get_password();

	int authenticate(int server_socket);
};
#endif