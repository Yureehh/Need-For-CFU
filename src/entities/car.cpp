#include "car.h"

// O O
//  O
// O O
// x verticale - y orizzontale

//Initialize the car
car::car(int asx , int asy ,
         int adx , int ady ,
         int ccx , int ccy ,
         int bsx , int bsy ,
         int bdx , int bdy )
         {
        as.x = asx; as.y = asy;
        ad.x = adx; ad.y = ady;
        cc.x = ccx; cc.y = ccy;
        bs.x = bsx; bs.y = bsy;
        bd.x = bdx; bd.y = bdy;
}
 
//prints the car
void car::stampa(){
    mvprintw(as.x, as.y, "O");
    mvprintw(ad.x, ad.y, "O");
    mvprintw(cc.x, cc.y, "X");
    mvprintw(bs.x, bs.y, "O");
    mvprintw(bd.x, bd.y, "O");
    refresh();
}

//deletes the car
void car::clean(){
    mvprintw(as.x, as.y, " ");
    mvprintw(ad.x, ad.y, " ");
    mvprintw(cc.x, cc.y, " ");
    mvprintw(bs.x, bs.y, " ");
    mvprintw(bd.x, bd.y, " ");
    refresh();
}

//Moves the car 1 to the right
bool car::destra(){
    if(ad.y < 46){
        as.y++;
        ad.y++;
        cc.y++;
        bs.y++;
        bd.y++;
        return true;
    }
    else{
        return false;
    } 
}

//Moves the car 1 to the left
bool car::sinistra(){
    if(as.y >2){
        as.y--;
        ad.y--;
        cc.y--;
        bs.y--;
        bd.y--;
        return true;
    }
    else{
        return false;
    }
}






