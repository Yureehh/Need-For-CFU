#include "car.h"

// O O
//  X
// O O
// x verticale - y orizzontale

//Initialize the car
car::car(){
    c.y = 38;
    c.x = 23;
}

car::car(int cy, int cx) {
    c.y = cy;
    c.x = cx;
}

posizione car::getPosition(){
    return c;
}

//prints the car
void car::stampa(){
    mvprintw(c.y, c.x, "O O");
    mvprintw(c.y + 1, c.x + 1, "X");
    mvprintw(c.y + 2, c.x, "O O");
    refresh();
}

//deletes the car
void car::clean(){
    mvprintw(c.y, c.x, "   ");
    mvprintw(c.y + 1, c.x + 1, " ");
    mvprintw(c.y + 2, c.x, "   ");
    refresh();
}

void car::move(int y, int x){
    c.y = c.y + y;
    c.x = c.x + x;
}
