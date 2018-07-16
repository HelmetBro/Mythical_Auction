#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <ctime>

#include <item.h>

class Storage{

private:

	std::vector<Item> items;

	int total_price;

	std::time_t time_loaded;

public:

};
#endif