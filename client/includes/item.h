#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <ctime>

class Item{

private:

	int ITEM_ID;

	//maybe graph of item value over past time in future
	int price_aquired;
	int current_price;

	std::time_t time_aquired;

public:

};
#endif