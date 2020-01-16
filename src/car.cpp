#include "car.h"

//12 13 14
// O O
//  O
// O O

car::car(int asx = 38, int asy = 23,
         int adx = 40, int ady = 23,
         int ccx=  39, int ccy = 24,
         int bsx = 38, int bsy = 25,
         int bdx = 40, int bdy = 25)
         {
        as.x = asx; as.y = asy;
        ad.x = adx; ad.y = ady;
        cc.x = ccx; cc.y = ccy;
        bs.x = bsx; bs.y = bsy;
        bd.x = bdx; bd.y = bdy;
}
    
void car::stampa(){
    mvprintw(as.x, as.y, "O");
    mvprintw(bs.x, as.y, "O");
    mvprintw(cc.x, cc.y, "X");
    mvprintw(ad.x, ad.y, "O");
    mvprintw(bd.x, bd.y, "O");
}

bool car::destra(){
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

bool car::sinistra(){
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





