#include <iostream>
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
    car();

    car(int, int);
    
    posizione getPosition();
    //prints the car
    void stampa();
    
    //deletes the car
    void clean();

    void move(int, int);
};

#endif