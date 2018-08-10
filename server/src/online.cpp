#include <pthread.h>
#include <iostream>

#include "online.h"

Online::Online(int backlog){
	this->size = backlog;
	this->ONLINE = new int[backlog];
}
Online::~Online(){
	delete[] this->ONLINE;
}

int Online::online(int user_id){
	pthread_mutex_lock(&this->mutex);

	//do better error checking here
	if(++last > size - 1){
		std::cout << "EXCEEDED MAX PLAYER LIMIT" << std::endl;
		return -1;
	}

	ONLINE[last] = user_id;
	
	pthread_mutex_unlock(&this->mutex);

	return 0;
}

/* There's no "empty" mutex variable because we don't care if 
we call offline, and it's already removed

also, I know this code is unefficient and trash. i know.*/
int Online::offline(int user_id){
	
	pthread_mutex_lock(&this->mutex);

	//search for index
	int index = 0;
	for(; index <= size; index++)
		if (index == size || ONLINE[index] == user_id)
			break;

	if(index == size){ // couldn't find, return and unlock
		pthread_mutex_unlock(&this->mutex);
		return 0;
	}

	//"delete" user
	ONLINE[index] = 0;

	//shift everything over
	for(; index < size - 1; index++)
		ONLINE[index] = ONLINE[index + 1];
	ONLINE[index] = 0;

	pthread_mutex_unlock(&this->mutex);

	return 0;
}



int Online::get_num_users(){
	return last + 1;
}