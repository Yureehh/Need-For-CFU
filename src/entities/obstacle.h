#include <iostream>
#include <ncurses.h>

using namespace std;

#ifndef OBSTACLE_H
#define OBSTACLE_H

class obstacle{

    protected:

        const char *c;
        int score;
        // int dim

    public:

        obstacle(const char*, int);          //costruttore per l'ostacolo
        obstacle();
        const char* getChar();
        int getScore();
};

#endif
