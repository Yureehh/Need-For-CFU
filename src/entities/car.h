#include <iostream>
#include <stdlib.h>
#include <ncurses.h>

using namespace std;

#ifndef CAR_H
#define CAR_H

struct posizione{
    int x;
    int y;
};

class car{

    protected:
        posizione c;

    public:
        // Default Constructor
        car(int, int);
        
        //prints the car
        void stampa();
        
        //deletes the car
        void clean();


        //Moves the car 1 to the right
        bool destra();

        //Moves the car 1 to the left
        bool sinistra();
};

#endif