#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include "storage.h"

class Profile{

private:

	std::string username;
	int bank;	//$
	int rep; 	//reputation

	//storage <- item history[with price bought it at, when it was aquired], current items [with current price]
	Storage storage;

public:

};
#endif