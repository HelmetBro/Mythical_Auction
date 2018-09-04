CFLAGS = -Wall -std=c++11# -Werror# -std=c99
CC = g++

DIR := ${CURDIR}

SOURCE = src
BIN = bin
INCLUDES = includes

OBJFILES = $(BIN)/main.o $(BIN)/response.o $(BIN)/online.o $(BIN)/disk_io.o
INCLUDES_DIR = -I$(DIR)/includes

all: main response online disk_io
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -pthread $(OBJFILES) -o server

main: $(SOURCE)/main.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/main.cpp -o $(BIN)/main.o

response: $(INCLUDES)/response.h $(SOURCE)/response.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/response.cpp -o $(BIN)/response.o

online: $(INCLUDES)/online.h $(SOURCE)/online.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/online.cpp -o $(BIN)/online.o

disk_io: $(INCLUDES)/disk_io.h $(SOURCE)/disk_io.cpp
	$(CC) $(INCLUDES_DIR) $(CFLAGS) -c $(SOURCE)/disk_io.cpp -o $(BIN)/disk_io.o


clean:
	rm -rf $(OBJFILES)
	rm server
