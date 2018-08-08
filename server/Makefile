CFLAGS = -Wall # -Werror# -std=c99
CC = g++

DIR := ${CURDIR}

SOURCE = src
BIN = bin
INCLUDES = includes

OBJFILES = $(BIN)/main.o $(BIN)/response.o $(BIN)/online.o 
INCLUDES_FLAG = -I$(DIR)/includes

all: main response online
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -pthread $(OBJFILES) -o server

main: $(SOURCE)/main.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/main.cpp -o $(BIN)/main.o

response: $(INCLUDES)/response.h $(SOURCE)/response.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/response.cpp -o $(BIN)/response.o

online: $(INCLUDES)/online.h $(SOURCE)/online.cpp
	$(CC) $(INCLUDES_FLAG) $(CFLAGS) -c $(SOURCE)/online.cpp -o $(BIN)/online.o

clean:
	rm -rf $(OBJFILES)
	rm server
