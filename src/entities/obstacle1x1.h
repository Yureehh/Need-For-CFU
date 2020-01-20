#include "car.h"
#include <iostream>
#include <ncurses.h>
using namespace std;

class obstacle1x1{
    protected:
    posizione position;

    public:
    obstacle1x1(int , int );
    posizione getPosition();
    void setPosition(int, int);
};

