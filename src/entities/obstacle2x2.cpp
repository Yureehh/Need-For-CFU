#include "obstacle2x2.h"

obstacle2x2::obstacle2x2(int x1, int y1, int x2, int y2,int x3, int y3,int x4, int y4):obstacle1x1(x1, y1){
    position2.x=x2;
    position2.y=y2;
    position3.x=x3;
    position3.y=y3;
    position4.x=x4;
    position4.y=y4;
}

//restituisce il quadratino in basso a sinistra
posizione obstacle2x2::getPosition(){
    obstacle1x1::getPosition();
}

//fa scendere di 1 riga l'ostacolo
void obstacle2x2::down(){
    obstacle1x1::down();               
    position2.y++;    
    position3.y++;
    position4.y++;                

}

//prints the ob
void obstacle2x2::stampa(){
    mvprintw(position.x, position.y, "%c", 79);
    mvprintw(position2.x, position2.y, "%c", 79);
    mvprintw(position3.x, position3.y, "%c", 79);
    mvprintw(position4.x, position4.y, "%c", 79);
    refresh();
}

//deletes the ob
void obstacle2x2::clean(){
    mvprintw(position.x, position.y, " ");
    mvprintw(position2.x, position2.y, " ");
    mvprintw(position3.x, position3.y, " ");
    mvprintw(position4.x, position4.y, " ");
    refresh();
}