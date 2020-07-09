#include <iostream>
#include <ncurses.h>
using namespace std;

#ifndef CAR_H
#define CAR_H

class car{

    protected:
        int x, y;
    
    public:

        car();
        car(int, int);

        // Getters
        int getX();
        int getY();

        //prints the car
        void stampa();
        
        //deletes the car
        void clean();

        void move(int, int);

};

#endif