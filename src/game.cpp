#include "game.h"
#include <unistd.h>

//Initialize the game
game::game(){
    c = car();
    current_Level = new level(1, 100, NULL);
}


//prints the game
void game::stampaUI(){

    for(int i = 0; i< height_UI; i++) {
        for (int j = 0; j < width_UI; j++) {
            if(i == 0 || i == height_UI-1) {
                mvprintw(i, j, new char('-'));
            }
            else {
                if(j == 0 || j == width_UI -1)
                    mvprintw(i, j, new char('|'));
                else if(j == 1 || j == width_Track + 2 )
                    mvprintw(i, j, new char('#'));
                else
                    mvprintw(i, j, new char(' ')); 
            }
        }
    }

}

void game::stampaCar(){
    c.stampa();
}

void game::cleanCar(){
    c.clean();
}

//Prints the words
void game::stampaScore(){
    mvprintw(20,58,"Stage: ");
    mvprintw(22,58,"Score: ");
}

bool game::sinistraCar(){
    // Actually move if not going outside the map
    if ( c.getPosition().x > 2 ){
        c.move( 0, -1 );
        return true;
    } else
        return false;
}

bool game::destraCar(){
    // Actually move if not going outside the map
    if ( c.getPosition().x < 46 ){
        c.move( 0, +1);
        return true;
    } else
        return false;
}

// True if the car is going to hit something

// ! REFACTOR
int game::hit(int pos){

    /* Left -> p -1
    ** Center -> p 0
    ** Right -> p 1 */
    chtype ch[3];

    if ( pos == -1 ) {
        ch[0] = mvinch(c.getPosition().y, c.getPosition().x - 1);
        ch[1] = mvinch(c.getPosition().y + 1, c.getPosition().x - 1);
        ch[2] = mvinch(c.getPosition().y + 2, c.getPosition().x - 1);
    } else if ( pos == 1 ) {
        ch[0] = mvinch(c.getPosition().y, c.getPosition().x + 3);
        ch[1] = mvinch(c.getPosition().y + 1, c.getPosition().x + 3);
        ch[2] = mvinch(c.getPosition().y + 2, c.getPosition().x + 3);
    } else if ( pos == 0 ) {
        ch[0] = mvinch(c.getPosition().y - 1, c.getPosition().x);
        ch[1] = mvinch(c.getPosition().y - 1, c.getPosition().x + 1);
        ch[2] = mvinch(c.getPosition().y - 1, c.getPosition().x + 2);
    }

    // If just one of the char checked is different than " ", then hit something
    return calcScore(ch) ;
}

int game::calcScore(chtype ch[3]){
    int score = 0;
    for (int i = 0; i < 3; i++){
        //score += obstacles[ch[i]];
    }
    mvprintw(25,58, "Add: %c + %c + %c = %d ", ch[0], ch[1], ch[2], score );
    return score;
}


//Downs the obstacles of 1 line
void game::downTrack(){

    int r = start_Track;

    for (int i = height_Track; i > 0; i--){
        for (int j = 0; j < width_Track; j++){
            // Loop when u finish the map
            if ( r > current_Level->get_Length() )
                r = 0;

            // Stamp the CHAR only when there is an obstacle -> !is_Free
            if ( current_Level->is_Free(r, j) )
                mvprintw(i, j+2, " " );
            else
                mvprintw(i, j+2, current_Level->get_Char( r , j) );
        }
        
        r++;

    }
    
    start_Track ++;

    if( start_Track > current_Level->get_Length() )
        start_Track = 0;

}
