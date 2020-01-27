#include <iostream>
#include <ncurses.h>

using namespace std;

#ifndef OBSTACLE_H
#define OBSTACLE_H

class obstacle{

protected:
    int x, y;

public:

    obstacle(int, int);          //costruttore per l'ostacolo

    posizione getPosition();        //restituisce la posizione del quadratino

    void down();                    //abbassa di 1 il quadratino

    void stampa();                  //prints the ob
        
    void clean();                   //deletes the ob
};

#endif
