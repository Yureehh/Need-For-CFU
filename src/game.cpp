#include "game.h"
#include <unistd.h>

//Initialize the game
game::game(){
    c = car();
    current_Level = new level(1, height_Track, NULL);
}



void game::clearLevel(){
    for(int i=0;i<height_Track;i++){
        for(int j=0;j<width_Track;j++){
            if(!current_Level->isFree(i,j) && (i!= 22 && j!= 7 && j!=11) ){
                current_Level->setVisibile(i,j);
                //cout<<"("<<i<<","<<j<<")"<<endl;
                //k++;
            }
                
        }
    }
}

void game::clearLine(){
    int i= abs(c.getPosition().y - 37 );
    for(int j=0; j<width_Track; j++){
        if(!current_Level->isFree(i,j) && (i!= 22 && j!= 7 && j!=11) )
                current_Level->setVisibile(i,j);
        
    }
}

void game::forwardNewLevel(int s){
    start_Track = 1;
    c = car();
    current_Level -> next = new level(s, height_Track, current_Level );
    current_Level = current_Level -> next;
}

void game::forwardLevel(){
    start_Track = 1;
    c = car();
    current_Level = current_Level -> next;
}

void game::backLevel(){
    start_Track = 1;
    c = car();
    current_Level = current_Level -> prev;
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

int game::getCarX(){
    return c.getPosition().x;
}

int game::getCarY(){
    return c.getPosition().y;
}

void game::avantiCar(){
    if(c.getPosition().y > 0)
        c.move( -1, 0);
    else{
        c.move(height_Track, 0);
    }
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
            if ( r >= current_Level->getLength() )
                r = 0;

            // Stamp the CHAR only when there is an obstacle -> !isFree
            if ( current_Level->isFree(r, j) )
                mvprintw(i, j+2, " " );
            else
                if ( current_Level->isVisible(r, j) )
                    mvprintw(i, j+2, current_Level->getChar(r, j) );
        }
        
        r++;

    }
    
    start_Track ++;

    if( start_Track > current_Level->getLength() )
        start_Track = 0;
        
}


void game::primaStampa(){

    int q = start_Track;

    for (int i = height_Track; i > 0; i--){
        for (int j = 0; j < width_Track; j++){
            // Stamp the CHAR only when there is an obstacle -> !isFree
            if ( current_Level->isFree(q, j) )
                mvprintw(i, j+2, " " );
            else
                mvprintw(i, j+2, current_Level->getChar(q, j) );
             }
        q++;
    }  
}

bool game::robo(){
    return current_Level->isVisible(abs( c.getPosition().y - 37 ), abs(c.getPosition().x ) );
}

int game::collisioni(){
    int malus = 0, bonus = 0;

    //ruota in alto a sx
    if( ! (current_Level->isFree( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) - 2 ) ) && 
        current_Level->isVisible(abs( c.getPosition().y - 39 ), abs(c.getPosition().x ) - 2 ) ){

        current_Level->hasHit( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) - 2 );

        if( current_Level->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) - 2) >= 0 )
            bonus += current_Level->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x - 2 ));

        else{
            if( abs (current_Level->getScore( abs(c.getPosition().y - 39 ), abs(c.getPosition().x - 2) ) )  > abs(malus) )
                malus = current_Level->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x - 2) );
        }

    }


    //ruota in alto a dx
    if( ! (current_Level->isFree( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) ) )  && 
        current_Level->isVisible(abs( c.getPosition().y - 39 ), abs(c.getPosition().x ) ) ){

            current_Level->hasHit( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) );

        if( current_Level->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) ) >= 0 )
            bonus += current_Level->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ));

        else{
            if( abs (current_Level->getScore( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) ) )  > abs(malus) )
                malus = current_Level->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) );
        }
    }


    //ruota in basso a sx
    if( ! (current_Level->isFree( abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) - 2 ) )  && 
        current_Level->isVisible(abs( c.getPosition().y - 37 ), abs(c.getPosition().x ) - 2 ) ){

            current_Level->hasHit( abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) - 2 );

        if( current_Level->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) - 2) >= 0 )
            bonus += current_Level->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2 ));

        else{
            if( abs (current_Level->getScore( abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2) ) )  > abs(malus) )
                malus = current_Level->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2) );
        }
    }

    //ruota in basso a dx
    if( ! (current_Level->isFree( abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) ) )  &&
        current_Level->isVisible(abs( c.getPosition().y - 37 ), abs(c.getPosition().x ) ) ){

            current_Level->hasHit( abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) );

        if( current_Level->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) ) >= 0 )
            bonus += current_Level->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ));

        else{
            if( abs (current_Level->getScore( abs(c.getPosition().y - 37 ), abs(c.getPosition().x) ) )  > abs(malus) )
                malus = current_Level->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) );
        }
    }

    //pilota
    if( ! (current_Level->isFree( abs(c.getPosition().y - 38 ), abs(c.getPosition().x ) - 1 ) )  && 
        current_Level->isVisible(abs( c.getPosition().y - 38 ), abs(c.getPosition().x ) - 1 ) ){

            current_Level->hasHit( abs(c.getPosition().y - 38 ), abs(c.getPosition().x ) - 1 );

        if( current_Level->getScore(abs(c.getPosition().y - 38 ), abs(c.getPosition().x ) - 1) >= 0 )
            bonus += current_Level->getScore(abs(c.getPosition().y - 38 ), abs(c.getPosition().x - 1 ));

        else{
            if( abs (current_Level->getScore( abs(c.getPosition().y - 38 ), abs(c.getPosition().x - 1) ) )  > abs(malus) )
                malus = current_Level->getScore(abs(c.getPosition().y - 38 ), abs(c.getPosition().x - 1) );
        }
    }
     

    return malus + bonus;
}
