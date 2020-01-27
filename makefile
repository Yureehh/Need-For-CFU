CC = g++
CFLAGS = -c
SRC = main game utilities scorestage level
SRC_ENT = car 

all : outrun

outrun : $(addprefix entities/,$(SRC_ENT)) $(SRC)
	$(CC) bin/*.o -o game -lncurses

%: src/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$@.o -lncurses
	
entities/% : src/entities/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$(subst entities/,,$@).o -lncurses

run : 
	./game

clean :
	rm -rf bin/*.o
