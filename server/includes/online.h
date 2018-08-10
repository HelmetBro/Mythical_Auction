#ifndef ONLINE_H
#define ONLINE_H

#include <pthread.h>

/*

Later gonna change the implementation to a linked-list or smth
THIS IS HELLA UN-EFFICIENT, BUT WORKS for now, change when i have time

*/

class Online{

private:

	int * ONLINE;
	int size;
	int	last = 0;	// index of last element in queue
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;	// mutual exclusion lock

public:

	Online(int user_id); //constructor
	~Online();

	int online(int user_id);
	int offline(int user_id);

	int get_num_users();

	//std::string get_usernames(); //could probably make this a friend of
	// the class that holds all the user data to get this?

};
#endif