#include "obstacle.h"

//set the obstacle position
obstacle::obstacle(int x, int y){
    position.x=x;
    position.y=y;
}

//getter for the coordinates
posizione obstacle::getPosition(){
    return position;
}

//fa scendere di 1 riga l'ostacolo
void obstacle::down(){
    position.x++;
}

//prints the ob
void obstacle::stampa(){
    mvprintw(position.x, position.y, "%c", 79);
    refresh();
}

//deletes the ob
void obstacle::clean(){
    mvprintw(position.x, position.y, " ");
    refresh();
}

