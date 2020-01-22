CC = g++
CFLAGS = -lncurses

all : game

game : main.o layout.o car.o scorestage.o obstacle1x1.o obstacle2x2.o obstacle1x2.o utilities.o
	$(CC) bin/*.o -o game $(CFLAGS)

main.o : layout.o car.o
	$(CC) -c src/main.cpp -o bin/main.o $(CFLAGS)

layout.o :
	$(CC) -c src/layout.cpp -o bin/layout.o $(CFLAGS)

car.o : 
	$(CC) -c src/entities/car.cpp -o bin/car.o

scorestage.o :
	$(CC) -c src/scorestage.cpp -o bin/scorestage.o $(CFLAGS)

obstacle1x1.o : 
	$(CC) -c src/entities/obstacle1x1.cpp -o bin/obstacle1x1.o

obstacle1x2.o : 
	$(CC) -c src/entities/obstacle1x2.cpp -o bin/obstacle1x2.o

obstacle2x2.o : 
	$(CC) -c src/entities/obstacle2x2.cpp -o bin/obstacle2x2.o

utilities.o :
	$(CC) -c src/utilities.cpp -o bin/utilities.o $(CFLAGS)

run : 
	./game

clean :
	rm -rf bin/*.o