CFLAGS = -Wall# -Werror# -std=c99
CC = g++

DIR := ${CURDIR}

SOURCE = src
BIN = bin
INCLUDES = includes

OBJFILES = $(BIN)/main.o $(BIN)/login.o $(BIN)/request.o $(BIN)/login_request.o
INCLUDES_FLAG = -I$(DIR)/includes

all: main login request login_request
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) $(OBJFILES) -o client -lncurses

main: $(SOURCE)/main.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/main.cpp -lncurses -o $(BIN)/main.o

login: $(INCLUDES)/login.h $(SOURCE)/login.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/login.cpp -o $(BIN)/login.o

request: $(INCLUDES)/request.h $(SOURCE)/request.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/request.cpp -o $(BIN)/request.o

login_request: $(INCLUDES)/login_request.h $(SOURCE)/login_request.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/login_request.cpp -o $(BIN)/login_request.o

clean:
	rm -rf $(OBJFILES)
	rm client
