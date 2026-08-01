CC = gcc

SRC = ./src
OBJ = ./obj
APP = ./app
BIN = ./bin
INC = ./include
EX = ./examples

.PHONY: all compile clean

all: compile

compile:
	$(CC) -c $(SRC)/doubly_linked_list.c -I $(INC) -o $(OBJ)/doubly_linked_list.o
	$(CC) -c $(SRC)/circular_doubly_linked_list.c -I $(INC) -o $(OBJ)/circular_doubly_linked_list.o
	$(CC) -c $(SRC)/static_stack.c -I $(INC) -o $(OBJ)/static_stack.o
	$(CC) -c $(SRC)/dinamic_stack.c -I $(INC) -o $(OBJ)/dinamic_stack.o

prog:
	$(CC) $(EX)/main.c $(OBJ)/*.o -I $(INC) -o $(EX)/main.bin

clean:
	rm -rf $(OBJ)/*
	rm -rf $(BIN)/*
	rm -rf $(EX)/*.bin
