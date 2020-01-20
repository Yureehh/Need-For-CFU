#include "obstacle1x1.h"

class obstacle2x2: public obstacle1x1{

protected:
    posizione position2;
    posizione position3;
    posizione position4;                            
public:

    obstacle2x2(int ,int , int , int, int, int, int, int);

    posizione getPosition();    // ritorna l'angolo in basso a sx

    void down();                //abbassa la posizione dei 2 quadratini in basso di 1

    void stampa();              //prints the ob
        
    void clean();               //deletes the ob
};
