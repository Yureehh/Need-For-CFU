#include "car.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

class obstacle2x2{
    protected:
    posizione position1, position2; //angolo in alto a sinistra
                                    // e angolo in basso a destra

    public:
    obstacle2x2(int ,int , int , int );
    posizione getPosition(); // ritorna l'angolo in basso a destra
    void setPosition(int ,int , int , int );

};
