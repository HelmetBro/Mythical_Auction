#include <ncurses.h>
#include <string>

#include "profile.h"
#include "login.h"

#define WINDOW_WIDTH 125
#define WINDOW_HEIGHT 40

const char * const IP_ADDRESS = "192.168.0.117";
const short PORT = 51992;

int server_socket;

int login(){

	Login login;
	login.print_login();

	//connect to server
	server_socket = login.establish_connection(IP_ADDRESS, PORT);

	bool verified = false;

	while (!verified){

		login.clear();

		login.print_username_prompt();
		login.get_username();
	
		login.print_password_prompt();
		login.get_password();
	
		verified = !login.authenticate(server_socket);

		if(!verified){
			printw("WRONG!");
			refresh();
		}
	}


	printw("SUCCESS!"); //print SUCCESS! or smth
	refresh();
	
	return 0;
}

int main(){ //could have argv arguments for MOD MODE

	//ncurses setup
	initscr();
	keypad(stdscr, TRUE);	//We get F1, F2, arrow keys, etc
	login();

	getch();//artificial delay
	endwin();
	return 0;
}