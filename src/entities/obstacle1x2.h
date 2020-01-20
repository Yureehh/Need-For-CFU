#include "obstacle1x1.h"

class obstacle1x2: public obstacle1x1{

protected:
    posizione position2;

public:

    obstacle1x2(int, int , int, int);                   //costruttore dei 2 quadratini

    posizione getPosition();                            //restituisce le coordinate del quadrato in basso a sx

    void down();                                        //abbassa la posizione dei 2 quadratini in basso di 1
    
    void stampa();                                      //prints the ob
        
    void clean();                                       //deletes the ob
};