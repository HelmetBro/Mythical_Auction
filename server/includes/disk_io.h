#ifndef DISK_IO_H
#define DISK_IO_H

#include <string>


/*
Later in development, replace all connections with OpenSSL
and do actual encryption.
*/

class Disk_IO{

private:

	static const int MAX_FILE_SIZE = 2000000; //20MB /*NOT IN USE AT THE MOMENT*/

	static const std::string resource_path;
	static const std::string request_history;
	static const std::string credentials;

	static pthread_mutex_t reqh_mutex;
	static pthread_mutex_t cred_mutex;

	static int write_to_file(std::string file_name, char * contents);

public:

	static int write_cred_file(char * contents);
	static int write_reqh_file(char * contents);

	//reads file and searches for credentials
	static int match_cred_file(std::string username, std::string password);

	int file_size(const char * file_name);

};

pthread_mutex_t Disk_IO::reqh_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t Disk_IO::cred_mutex = PTHREAD_MUTEX_INITIALIZER;

const std::string Disk_IO::resource_path = "resources/";
const std::string Disk_IO::request_history = resource_path + "request_history.txt";
const std::string Disk_IO::credentials = resource_path + "credentials.txt";

#endif

