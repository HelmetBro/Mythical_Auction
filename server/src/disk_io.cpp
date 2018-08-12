#include <fstream>
#include <limits>
#include <string>

#include "disk_io.h"




int Disk_IO::write_to_file(std::string file_name, char * contents){
	std::ofstream file;
	file.open(file_name, std::ios::out | std::ios::app);
	file << contents;
	file.close();
	return 0;
}

int Disk_IO::write_cred_file(char * contents){
	pthread_mutex_lock(&this->cred_mutex);
	write_to_file(this->credentials, contents);
	pthread_mutex_unlock(&this->cred_mutex);
	return 0;
}

int Disk_IO::write_reqh_file(char * contents){
	pthread_mutex_lock(&this->reqh_mutex);
	write_to_file(this->request_history, contents);
	pthread_mutex_unlock(&this->reqh_mutex);
	return 0;
}


/* THIS METHOD EXISTS FOR FUTURE OPTIMIZATIONS.
NOT IN USE AT THE MOMENT*/
//figure out a faster way to do this
int Disk_IO::file_size(const char * file_name){

	std::ifstream file;

	file.open(file_name, std::ios::in | std::ios::binary);
	file.ignore(std::numeric_limits<std::streamsize>::max());
	std::streamsize length = file.gcount();
	// file.clear(); //clear flags
	// file.seekg( 0, std::ios_base::beg);
	file.close();
	
	return length;
}