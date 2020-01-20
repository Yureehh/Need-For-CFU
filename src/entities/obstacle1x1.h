#include <iostream>
#include <ncurses.h>
#include "car.h"
using namespace std;

#ifndef OBSTACLE_H
#define OBSTACLE_H

class obstacle1x1{

protected:
    posizione position;

public:

    obstacle1x1(int, int);          //costruttore per l'ostacolo

    posizione getPosition();        //restituisce la posizione del quadratino

    void down();                    //abbassa di 1 il quadratino

    void stampa();                  //prints the ob
        
    void clean();                   //deletes the ob
};

#endif
