#include <iostream>
#include <stdlib.h>
#include <conio.h>

//12 13 14
// O O
//  O
// O O

struct posizione{
    int x;
    int y;
};


class car{

protected:
    posizione as, ad, bs, bd;

public:
    car(int asx = 12, int asy = 27,
        int adx = 14, int ady = 27,
        int bsx = 12, int bsy = 29,
        int bdx = 14, int bdy = 29){

            as.x = asx; as.y = asy;
            ad.x = adx; ad.y = ady;
            bs.x = bsx; bs.y = bsy;
            bd.x = bdx; bd.y = bdy;
    }
    

    bool destra(){
        if(ad.x < 26){
            as.x++;
            ad.x++;
            bs.x++;
            bd.x++;
            return true;
        }
        else{
            return false;
        } 
    }

    bool sinistra(){
        if(as.x >2){
            as.x--;
            ad.x--;
            bs.x--;
            bd.x--;
            return true;
        }
        else{
            return false;
        }
    }

}





