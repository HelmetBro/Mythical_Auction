#include <fstream>
#include <limits>
#include <string>

#include "disk_io.h"

int Disk_IO::match_cred_file(std::string username, std::string password){
	pthread_mutex_lock(&Disk_IO::cred_mutex);
	std::ifstream file;
	file.open(Disk_IO::credentials, std::ios::out);
	
	if(!file) //cant open file!!
		exit(-1);

	std::string line;

	while(std::getline(file, line)){
		
		if(line.at(0) == 'U' && line.substr(2) == username){ //2 for "U " prefix on usernames
			std::getline(file, line);
			if(line.at(0) == 'P' && line.substr(2) == password) // ^ ditto but for p
				return 0; //valid!
		}
	}

	file.close();
	pthread_mutex_unlock(&Disk_IO::cred_mutex);
	return -1; //not found
}


int Disk_IO::write_to_file(std::string file_name, char * contents){
	std::ofstream file;
	file.open(file_name, std::ios::out | std::ios::app);
	file << contents;
	file.close();
	return 0;
}

int Disk_IO::write_cred_file(char * contents){
	pthread_mutex_lock(&Disk_IO::cred_mutex);
	write_to_file(Disk_IO::credentials, contents);
	pthread_mutex_unlock(&Disk_IO::cred_mutex);
	return 0;
}

int Disk_IO::write_reqh_file(char * contents){
	pthread_mutex_lock(&Disk_IO::reqh_mutex);
	write_to_file(Disk_IO::request_history, contents);
	pthread_mutex_unlock(&Disk_IO::reqh_mutex);
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