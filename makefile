CC = g++
CFLAGS = -lncurses

all : game

game : main.o layout.o car.o scorestage.o
	$(CC) bin/*.o -o game $(CFLAGS)

main.o : layout.o car.o
	$(CC) -c src/main.cpp -o bin/main.o $(CFLAGS)

layout.o :
	$(CC) -c src/layout.cpp -o bin/layout.o $(CFLAGS)

car.o : 
	$(CC) -c src/entities/car.cpp -o bin/car.o

scorestage.o :
	$(CC) -c src/scorestage.cpp -o bin/scorestage.o $(CFLAGS)

run : 
	./game

clean :
	rm -rf bin/*.o