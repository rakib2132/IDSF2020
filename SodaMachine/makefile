#Rakib Hossain ID: 1001514252
#makefile for C++ program
SRC = Code2_1001514252.cpp
OBJ = $(SRC:.cpp=.o)
EXE = $(SRC:.cpp=.e)
HFILES = SnackMachine.h
CFLAGS = -g -std=c++11

all : $(EXE)

$(EXE) : $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o $(EXE)

$(OBJ) : $(SRC)
	g++ -c $(SRC)
