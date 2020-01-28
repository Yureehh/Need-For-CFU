CC = g++
CFLAGS = -c
SRC = utilities scorestage level game main
SRC_ENT = car 

all : clean outrun

outrun : $(addprefix entities/,$(SRC_ENT)) $(SRC)
	$(CC) bin/*.o -o outrun -lncurses

%: src/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$@.o -lncurses
	
entities/% : src/entities/%.cpp
	$(CC) $(CFLAGS) $< -o bin/$(subst entities/,,$@).o -lncurses

run : 
	./outrun

clean :
	rm -rf bin/*.o
