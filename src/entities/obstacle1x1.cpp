#include "obstacle1x1.h"

//set the obstacle position
obstacle1x1::obstacle1x1(int x, int y){
    position.x=x;
    position.y=y;
}

//getter for the coordinates
posizione obstacle1x1::getPosition(){
    return position;
}

//fa scendere di 1 riga l'ostacolo
void obstacle1x1::down(){
    position.x++;
}

//prints the ob
void obstacle1x1::stampa(){
    mvprintw(position.x, position.y, "%c", 79);
    refresh();
}

//deletes the ob
void obstacle1x1::clean(){
    mvprintw(position.x, position.y, " ");
    refresh();
}

