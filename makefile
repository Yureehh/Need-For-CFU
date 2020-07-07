CC = g++
CFLAGS = -c
SRC = scorestage level game main
SRC_ENT = car obstacle

all : clean initalc

initalc : $(addprefix entities/,$(SRC_ENT)) $(SRC)	
	$(CC) bin/*.o -o initalc -lncurses -lmenu

%: src/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$@.o -lncurses -lmenu
	
entities/% : src/entities/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$(subst entities/,,$@).o -lncurses

run : 
	./initalc

clean :
	rm -rf bin
	mkdir bin
