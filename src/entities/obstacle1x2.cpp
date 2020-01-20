#include "obstacle1x2.h"

//costruttore dei 2 quadratini
obstacle1x2::obstacle1x2(int x1, int y1, int x2, int y2):obstacle1x1(x1, y1){
        position2.x = x2;
        position2.y = y2;
}

//restituisce il quadrato a sinistra
posizione obstacle1x2::getPosition(){
        obstacle1x1::getPosition();
}

//fa scendere di 1 riga l'ostacolo
void obstacle1x2::down(){
        obstacle1x1::down();
        position2.x++;
    }

//prints the ob
void obstacle1x2::stampa(){
    mvprintw(position.x, position.y, "%c", 79);
    mvprintw(position2.x, position2.y, "%c", 79);
    refresh();
}

//deletes the ob
void obstacle1x2::clean(){
    mvprintw(position.x, position.y, " ");
    mvprintw(position2.x, position2.y, " ");
    refresh();
}
