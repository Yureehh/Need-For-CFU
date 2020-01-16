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


    // # Car has 4 position for each tire
    protected:
        posizione as, ad, cc, bs, bd;

    public:
        // Default Constructor
        car(int, int, int, int, int, int, int, int, int, int);
        
        void stampa();
        bool destra();
        bool sinistra();
};

#endif