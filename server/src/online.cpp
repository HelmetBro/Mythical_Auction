#include <pthread.h>

#include "online.h"

Online::Online(int backlog){
	this->size = backlog;
	this->ONLINE = new int[backlog];
}
Online::~Online(int backlog){
	delete[] this->ONLINE;
}

int Online::online(int user_id){

	pthread_mutex_lock(&this->mutex);

}

int Online::offline(int user_id){
	
}