#ifndef ONLINE_H
#define ONLINE_H

#include <pthread.h>

/*

Later change the implementation to a linked-list or smth
THIS IS HELLA UN-EFFICIENT, BUT WORKS

*/

class Online{

private:

	int * const ONLINE;
	int size;
	int	num_users = 0;					// number of elements in the queue
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;	// mutual exclusion lock

public:

	Online(int user_id); //constructor
	~Online();

	int online(int user_id);
	int offline(int user_id);

	//std::string get_online_users();

};
#endif