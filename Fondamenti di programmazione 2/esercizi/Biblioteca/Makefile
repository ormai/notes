# Max debug info and all warnings
CC=g++
CFLAGS=-std=c++11 -ggdb -Wall

all: Biblioteca

Biblioteca: Biblioteca.o
	$(CC) $(CFLAGS) -o $@ $^ main.cpp
	#  $@ = target biblioteca
	#  $^ = dependency biblioteca.o

Biblioteca.o: Biblioteca.cpp Biblioteca.hpp
	$(CC) $(CFLAGS) -c Biblioteca.cpp

test: Biblioteca # rebuild if necessary
	./Biblioteca
clean: # make clean
	$(RM) Biblioteca *.o
