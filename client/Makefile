CFLAGS = -Wall -std=c++11# -Werror# -std=c99
CC = g++

DIR := ${CURDIR}

SOURCE = src
BIN = bin
INCLUDES = includes

OBJFILES = $(BIN)/main.o $(BIN)/login.o $(BIN)/request.o $(BIN)/response.o $(BIN)/login_request.o \
			$(BIN)/login_response.o
INCLUDES_DIR = -I$(DIR)/includes -I$(DIR)/api

all: main login request response login_request login_response
	$(CC) $(INCLUDES_DIR) $(CFLAGS) $(OBJFILES) -o client -lncurses

main: $(SOURCE)/main.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/main.cpp -lncurses -o $(BIN)/main.o

login: $(INCLUDES)/login.h $(SOURCE)/login.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/login.cpp -o $(BIN)/login.o

request: $(INCLUDES)/request.h $(SOURCE)/request.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/request.cpp -o $(BIN)/request.o

response: $(INCLUDES)/response.h $(SOURCE)/response.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/response.cpp -o $(BIN)/response.o

login_request: $(INCLUDES)/login_request.h $(SOURCE)/login_request.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/login_request.cpp -o $(BIN)/login_request.o

login_response: $(INCLUDES)/login_response.h $(SOURCE)/login_response.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/login_response.cpp -o $(BIN)/login_response.o

clean:
	rm -rf $(OBJFILES)
	rm client
