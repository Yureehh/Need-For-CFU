#include "car.h"

// O O
//  X
// O O
// x verticale - y orizzontale

//Initialize the car
car::car(){
    c.y = 37;
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
    mvprintw(38, c.x, "O");
    mvprintw(38, c.x+2, "O");
    mvprintw(39, c.x + 1, "X");
    mvprintw(40, c.x, "O");
    mvprintw(40, c.x+2, "O");
    refresh();
}

//deletes the car
void car::clean(){
    mvprintw(38, c.x, "   ");
    mvprintw(39, c.x + 1, " ");
    mvprintw(40, c.x, "   ");
    refresh();
}

void car::move(int y, int x){
    c.y = c.y + y;
    c.x = c.x + x;
}
