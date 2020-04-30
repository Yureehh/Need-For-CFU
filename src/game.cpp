#include "game.h"


//Initialize the game
game::game(){
    c = car();
    currentLevel = new level(1, HEIGHT_TRACK, NULL);
}


void game::clearLevel(){
    for(int i=0;i<HEIGHT_TRACK;i++){
        for(int j=0;j<WIDTH_TRACK;j++){
            if(!currentLevel->isFree(i,j) && (i!= 22 && j!= 7 && j!=11) )
                currentLevel->setVisible(i,j, true);  
        }
    }
}

void game::clearLine(){
    int i= abs(c.getPosition().y - 37 );
    for(int j=0; j<WIDTH_TRACK; j++){
        if(!currentLevel->isFree(i,j) && (i!= 22 && j!= 7 && j!=11) )
                currentLevel->setVisible(i,j, true);
    }
}



//prints the game
void game::printUI(){

    for(int i = 0; i< HEIGHT_UI; i++) {
        for (int j = 0; j < WIDTH_UI; j++) {
            if(i == 0 || i == HEIGHT_UI-1) {
                mvprintw(i, j, new char('-'));
            }
            else {
                if(j == 0 || j == WIDTH_UI -1)
                    mvprintw(i, j, new char('|'));
                else if(j == 1 || j == WIDTH_TRACK + 2 )
                    mvprintw(i, j, new char('#'));
                else
                    mvprintw(i, j, new char(' ')); 
            }
        }
    }
}


void game::carPrint(){
    c.stampa();
}

void game::carClean(){
    c.clean();
}

//Prints the words
void game::printScore(){
    mvprintw(20,58,"Stage: ");
    mvprintw(22,58,"Score: ");
}

bool game::carLeft(){
    // Actually move if not going outside the map
    if ( c.getPosition().x > 2 ){
        c.move( 0, -1 );
        return true;
    } else
        return false;
}

bool game::carRight(){
    // Actually move if not going outside the map
    if ( c.getPosition().x < 46 ){
        c.move( 0, +1);
        return true;
    } else
        return false;
}

void game::carForward(){
    if(c.getPosition().y > 0)
        c.move( -1, 0);
    else{
        c.move(HEIGHT_TRACK, 0);
    }
}


//Downs the obstacles of 1 line
void game::downTrack(){

    int r = start_Track;

    for (int i = HEIGHT_TRACK; i > 0; i--){
        for (int j = 0; j < WIDTH_TRACK; j++){
            // Loop when u finish the map
            if ( r >= currentLevel->getLength() )
                r = 0;

            // Stamp the CHAR only when there is an obstacle -> !isFree
            if ( currentLevel->isFree(r, j) )
                mvprintw(i, j+2, " " );
            else{
                if ( currentLevel->isVisible(r, j) ){
                    attron(COLOR_PAIR(currentLevel->getColor(r, j)));
                    mvprintw(i, j+2, currentLevel->getChar(r, j) );
                    attroff(COLOR_PAIR(currentLevel->getColor(r, j)));
                }
            }
        }
        
        r++;

    }
    
    start_Track ++;

    if( start_Track > currentLevel->getLength() )
        start_Track = 0;
        
}



int game::collisionCheck(int y, int x){
       
    int malus = 0, bonus = 0;


    if( ! (currentLevel->isFree(y, x) && currentLevel->isVisible(y, x) ) ){

        currentLevel->setVisible( y, x, false);

        if(currentLevel->getScore(y, x)  > 0)
            bonus += currentLevel->getScore(y, x);


    /*
      
        if( (abs (currentLevel->getScore( y, x) ) )  > ( abs(malus) ) )
            malus = currentLevel->getScore(y, x);
        */


    }
    
    
    return malus + bonus;   
    
}


int game::collisions(){
    
        /*    int tot=0;

            tot = collisionCheck( abs(c.getPosition().y - 39 ), abs(c.getPosition().x  - 2) );  //ruota in alto a sx
            //collisionCheck( abs(c.getPosition().y - 39 ) , c.getPosition().x , 0 ) +  //ruota in alto a dx

            //collisionCheck( abs(c.getPosition().y - 37 ), c.getPosition().x , 2 ) +  //ruota in basso a sx
            //collisionCheck( abs(c.getPosition().y - 37 ), c.getPosition().x , 0 ) +  //ruota in basso a dx

            //collisionCheck( abs(c.getPosition().y - 38 ), c.getPosition().x , 1 );   //pilota
      return tot;

*/

    int malus=0, bonus=0;
    if( ! (currentLevel->isFree( abs(c.getPosition().y - 39 ), abs(c.getPosition().x -2)  ) ) && 
        currentLevel->isVisible(abs( c.getPosition().y - 39 ), abs(c.getPosition().x -2)  ) ){

        currentLevel->setVisible( abs(c.getPosition().y - 39 ), abs(c.getPosition().x -2) , false );

        if( currentLevel->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x -2) ) >= 0 )
            bonus += currentLevel->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x - 2 ));

        else{
            if( abs (currentLevel->getScore( abs(c.getPosition().y - 39 ), abs(c.getPosition().x - 2) ) )  > abs(malus) )
                malus = currentLevel->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x - 2) );
        }

    }


    
    if( ! (currentLevel->isFree( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) ) )  && 
        currentLevel->isVisible(abs( c.getPosition().y - 39 ), abs(c.getPosition().x ) ) ){

            currentLevel->setVisible( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ), false );

        if( currentLevel->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) ) >= 0 )
            bonus += currentLevel->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ));

        else{
            if( abs (currentLevel->getScore( abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) ) )  > abs(malus) )
                malus = currentLevel->getScore(abs(c.getPosition().y - 39 ), abs(c.getPosition().x ) );
        }
    }


    //ruota in basso a sx
    if( ! (currentLevel->isFree( abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2 ) ) )  && 
        currentLevel->isVisible(abs( c.getPosition().y - 37 ), abs(c.getPosition().x - 2 ) ) ){

            currentLevel->setVisible( abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2), false );

        if( currentLevel->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x  - 2) ) >= 0 )
            bonus += currentLevel->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2 ));

        else{
            if( abs (currentLevel->getScore( abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2) ) )  > abs(malus) )
                malus = currentLevel->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x - 2) );
        }
    }

    //ruota in basso a dx
    if( ! (currentLevel->isFree( abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) ) )  &&
        currentLevel->isVisible(abs( c.getPosition().y - 37 ), abs(c.getPosition().x ) ) ){

            currentLevel->setVisible( abs(c.getPosition().y - 37 ), abs(c.getPosition().x ), false );

        if( currentLevel->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) ) >= 0 )
            bonus += currentLevel->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ));

        else{
            if( abs (currentLevel->getScore( abs(c.getPosition().y - 37 ), abs(c.getPosition().x) ) )  > abs(malus) )
                malus = currentLevel->getScore(abs(c.getPosition().y - 37 ), abs(c.getPosition().x ) );
        }
    }

    //pilota
    if( ! (currentLevel->isFree( abs(c.getPosition().y - 38 ), abs(c.getPosition().x  - 1 ) ) )  && 
        currentLevel->isVisible(abs( c.getPosition().y - 38 ), abs(c.getPosition().x  - 1 ) ) ) {

            currentLevel->setVisible( abs(c.getPosition().y - 38 ), abs(c.getPosition().x  - 1), false );

        if( currentLevel->getScore(abs(c.getPosition().y - 38 ), abs(c.getPosition().x ) - 1) >= 0 )
            bonus += currentLevel->getScore(abs(c.getPosition().y - 38 ), abs(c.getPosition().x - 1 ));

        else{
            if( abs (currentLevel->getScore( abs(c.getPosition().y - 38 ), abs(c.getPosition().x - 1) ) )  > abs(malus) )
                malus = currentLevel->getScore(abs(c.getPosition().y - 38 ), abs(c.getPosition().x - 1) );
        }
    }
     

    return malus + bonus; 
    
}

void game::forwardNewLevel(int s){
    start_Track = 1;
    c = car();
    currentLevel -> next = new level(s, HEIGHT_TRACK, currentLevel );
    currentLevel = currentLevel -> next;
}

void game::forwardLevel(){
    start_Track = 1;
    c = car();
    currentLevel = currentLevel -> next;
}

void game::backLevel(){
    start_Track = 1;
    c = car();
    currentLevel = currentLevel -> prev;
}

bool game::loss(scorestage s){

    if(s.getScore() <= 0){
        erase();
        mvprintw(21, 17, "Take the L!");
        mvprintw(23, 5, "Your record this run has been %d points!", s.getMaxScore());
        while(!kbhit());
        return true;
    }
    return false;
}