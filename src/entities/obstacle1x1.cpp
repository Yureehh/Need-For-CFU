#include "obstacle1x1.h";
obstacle1x1::obstacle1x1(int x, int y){
    position.x=x;
    position.y=y;
}
posizione obstacle1x1::getPosition(){
    return position;
}
void obstacle1x1::setPosition(int x, int y){//bisogna muovere tramite la x per 
    position.x=x;                           // far "scrorrere" l'ostacolo
    position.y=y;
}