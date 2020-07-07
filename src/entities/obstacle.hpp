#include <iostream>
#include <ncurses.h>
using namespace std;

#ifndef OBSTACLE_H
#define OBSTACLE_H

class obstacle{

protected:
    const char *c;
    int score;
    int color;
public:
    obstacle();
    obstacle(const char*, int, int);          //costruttore per l'ostacolo
    const char* getChar();
    int getScore();
    int getColor();
};

#endif
