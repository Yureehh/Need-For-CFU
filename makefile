CC = g++
CFLAGS = -lncurses

all : game

game : main.o layout.o
	$(CC) bin/*.o -o game $(CFLAGS)

main.o : layout.o
	$(CC) -c src/main.cpp -o bin/main.o $(CFLAGS)

layout.o :
	$(CC) -c src/layout.cpp -o bin/layout.o $(CFLAGS)

run : 
	./game
