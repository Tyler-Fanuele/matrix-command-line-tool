CC = g++
CFLAGS = -Werror -Wall -pedantic -std=c++20

all : matrix

matrix : main.o
	$(CC) $(CFLAGS) -o matrix main.o

main.o : main.cpp matrix.hpp
	$(CC) $(CFLAGS) -c main.cpp

clean: 
	rm -f *.o
	rm -f matrix