#include <iostream>
#include <stdlib.h>

#ifndef MACCHINA_H
#define MACCHINA_H

struct posizione{
    int x;
    int y;
};

class car{

    //12 13 14
    // O O
    //  O
    // O O

    // # Car has 4 position for each tire
    protected:
        posizione as, ad, bs, bd;

    public:
        // Default Constructor
        car(int, int, int, int ,
            int, int, int, int);
        
        bool destra();
        bool sinistra();
};

#endif