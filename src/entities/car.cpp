#include "car.h"

// O O
//  O
// O O
// x verticale - y orizzontale

//Initialize the car
car::car(int cy , int cx) {
    c.y = cx;
    c.x = cy;
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

//Moves the car 1 to the right
bool car::destra(){
    if(c.x < 46){
        c.x++;
        return true;
    }
    else{
        return false;
    }
}

//Moves the car 1 to the left
bool car::sinistra(){
    if(c.x > 2){
        c.x--;
        return true;
    }
    else{
        return false;
    }
}






