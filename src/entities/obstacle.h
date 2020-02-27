#include <iostream>
#include <ncurses.h>

using namespace std;

#ifndef OBSTACLE_H
#define OBSTACLE_H

class obstacle{

    protected:

        char c;
        int score;
        // int dim

    public:

        obstacle(int, int, int);          //costruttore per l'ostacolo

};

#endif
