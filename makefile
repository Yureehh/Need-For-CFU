CC = g++
CFLAGS = -c
SRC = main layout utilities scorestage
SRC_ENT = car obstacle

all : game

game : $(SRC) $(addprefix entities/,$(SRC_ENT))
	$(CC) bin/*.o -o game -lncurses

%: src/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$@.o -lncurses
	
entities/% : src/entities/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$(subst entities/,,$@).o -lncurses

run : 
	./game

clean :
	rm -rf bin/*.o
