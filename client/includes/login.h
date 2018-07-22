#ifndef LOGIN_H
#define LOGIN_H

#include <string>

#include "login_request.h"

class Login {

private:

	LoginRequest l_request;

public:

	int establish_connection(const char * const host, short port);

	void print_login();
	void print_username_prompt();
	void print_password_prompt();

	int get_username();
	int get_password();

	int authenticate(int server_socket);
};
#endif