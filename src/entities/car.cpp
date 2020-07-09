#include "car.hpp"

car::car(){
    this->y = 48;
    this->x = 23;
}

car::car(int y, int x){
    this->y = y;
    this->x = x;
}

// Getters
int car::getX(){
    return x;
}

int car::getY(){
    return y;
}

// Prints the car
void car::stampa(){
    mvprintw(38, x - 1 + 2, "O");
    mvprintw(38, x + 1 + 2, "O");
    mvprintw(39, x + 2, "X");
    mvprintw(40, x - 1 + 2, "O");
    mvprintw(40, x + 1 + 2, "O");
    refresh();
}

// Deletes the car
void car::clean(){
    mvprintw(38, x - 1 + 2, "   ");
    mvprintw(39, x + 2, " ");
    mvprintw(40, x - 1 + 2, "   ");
    refresh();
}
// Changes car coordinates
void car::move(int y, int x){
    this->y = this->y + y;
    this->x = this->x + x;
}
