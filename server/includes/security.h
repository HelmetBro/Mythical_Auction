#ifndef SECURITY_H
#define SECURITY_H

#include <string>
#include <ctime>

#define SIGNATURE_SIZE 1


//


class Security{

private:

public:

	static int verify_login(std::string username, std::string password);

	static void encrypt_string(char * string);
};
#endif