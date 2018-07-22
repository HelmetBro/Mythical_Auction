#include <ncurses.h>
#include <iostream>
#include <string>

#include "profile.h"
#include "login.h"

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 40

const char * const IP_ADDRESS = "192.168.0.117";
const short PORT = 51992;

int server_socket;

int login(){

	Login login_activity;
	login_activity.print_login();

	//connect to server
	server_socket = login_activity.establish_connection(IP_ADDRESS, PORT);

	bool verified = false;

	while (!verified){

		login_activity.print_username_prompt();
		login_activity.get_username();
	
		login_activity.print_password_prompt();
		login_activity.get_password();
	
		verified = !login_activity.authenticate(server_socket);
	}

	return 0;
}

int main(){ //could have argv arguments for MOD MODE

	//ncurses setup
	// initscr();
	// cbreak();
	// noecho();
	// keypad(stdscr, TRUE);

	// int h, w;
   	// getmaxyx(stdscr, h, w);
	// WINDOW * win = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);

	//make connection / check for updates
	login();
	//login

	// endwin();
	return 0;
}