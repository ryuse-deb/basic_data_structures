CC = gcc

SRC = ./src
OBJ = ./obj
APP = ./app
BIN = ./bin
INC = ./include

.PHONY: all compile clean

all: compile

compile:
	$(CC) -c $(SRC)/doubly_linked_list.c -I $(INC) -o $(OBJ)/doubly_linked_list.o
	
clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
