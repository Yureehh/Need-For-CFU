#include "car.h"

// O O
//  X
// O O
// x verticale - y orizzontale

//Initialize the car
car::car(int cy, int cx) {
    c.x = cx;
    c.y = cy;
}

//prints the car
void car::stampa(){
    mvprintw(c.x, c.y, "O O");
    mvprintw(c.x + 1, c.y + 1, "X");
    mvprintw(c.x + 2, c.y, "O O");
    refresh();
}

//deletes the car
void car::clean(){
    mvprintw(c.x, c.y, "   ");
    mvprintw(c.x + 1, c.y + 1, " ");
    mvprintw(c.x + 2, c.y, "   ");
    refresh();
}

/*
void car::move(x,y){
    c.x = x;
    c.y = y;
}
*/

//Moves the car 1 to the right
bool car::destra(){
    if(c.y < 46){
        c.y++;
        return true;
    }
    else{
        return false;
    }
}

//Moves the car 1 to the left
bool car::sinistra(){
    if(c.y > 2){
        c.y--;
        return true;
    }
    else{
        return false;
    }
}






