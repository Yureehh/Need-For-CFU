#include "obstacle2x2.h";
obstacle2x2::obstacle2x2(int x1, int y1, int x2, int y2){
    position1.x=x1;
    position1.y=y1;
    position2.x=x2;
    position2.y=y2;
}
posizione obstacle2x2::getPosition(){
    return position2;
}
void obstacle2x2::setPosition(int x1, int y1, int x2, int y2){
    position1.x=x1;                   // far "scrorrere" l'ostacolo
    position1.y=y1;                   //bisogna muovere tramite la x per
    position2.x=x2;
    position2.y=y2;                    
    
}