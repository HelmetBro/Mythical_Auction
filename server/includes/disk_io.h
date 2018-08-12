#ifndef DISK_IO_H
#define DISK_IO_H

#include <string>

class Disk_IO{

private:

	const int MAX_FILE_SIZE = 2000000; //20MB /*NOT IN USE AT THE MOMENT*/

	std::string request_history = "request_history.txt";
	std::string credentials = "credentials.txt";

	pthread_mutex_t reqh_mutex = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t cred_mutex = PTHREAD_MUTEX_INITIALIZER;

	int write_to_file(std::string file_name, char * contents);

public:

	int write_cred_file(char * contents);
	int write_reqh_file(char * contents);

	int file_size(const char * file_name);

};
#endif

