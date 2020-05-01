#include "game.h"


//Initialize the game
game::game(int s){
    currentLevel = new level(s, HEIGHT_TRACK, NULL, true);
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
    c = car(currentLevel->getLength() - 2, 23);
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
    int i = (c.getPosition().y + 2) % currentLevel->getLength();
    for(int j=0; j<WIDTH_TRACK; j++){
        if(!currentLevel->isFree(i,j))
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
                if(j == 0 || j == WIDTH_UI - 1)
                    mvprintw(i, j, new char('|'));
                else if(j == 1 || j == WIDTH_TRACK + 2 )
                    mvprintw(i, j, new char('#'));
                else
                    mvprintw(i, j, new char(' ')); 
            }
        }
    }
}

//Prints the words
void game::printScore(){
    mvprintw(20,58,"Stage: ");
    mvprintw(22,58,"Score: ");
}

void game::carPrint(){
    c.stampa();
}

void game::carClean(){
    c.clean();
}

bool game::carLeft(){
    // Actually move if not going outside the map
    if ( c.getPosition().x > 1 ){
        c.move( 0, -1 );
        return true;
    } else
        return false;
}

bool game::carRight(){
    // Actually move if not going outside the map
    if ( c.getPosition().x < 45 ){
        c.move( 0, +1);
        return true;
    } else
        return false;
}

void game::carForward(){
    if(c.getPosition().y > 0)
        c.move( -1, 0);
    else
        c.move(HEIGHT_TRACK - 1, 0);
}

void game::printTrack(){

    int r = start_Track;

    mvprintw( 24, 66, "%d ", start_Track);

    for (int i = 0; i < HEIGHT_TRACK; i++){
        for (int j = 0; j < WIDTH_TRACK; j++){
            // Loop when u finish the map
            if ( r >= currentLevel->getLength() )
                r = 0;
            // Stamp the CHAR only when there is an obstacle -> !isFree
            if ( currentLevel->isFree(r, j) )
                mvprintw( i+1, j+2, " " );
            else{
                if ( currentLevel->isVisible(r, j) ){
                    attron(COLOR_PAIR(currentLevel->getColor(r, j)));
                    mvprintw(i+1, j+2, currentLevel->getChar(r, j) );
                    attroff(COLOR_PAIR(currentLevel->getColor(r, j)));
                }
            }
        }

        mvprintw(i + 1, WIDTH_TRACK + 2, "%d ", r);
        r++;

    }

}

//Downs the obstacles of 1 line
void game::downTrack(){

    start_Track --;

    if( start_Track < 0)
        start_Track = currentLevel->getLength() - 1;

    printTrack();
    carForward();
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

    int malus=0, bonus=0, score=0;

    int x = c.getPosition().x;
    int y = c.getPosition().y;
    
    mvprintw( 26, 66, "%d - %d ", x, y );

    //pilota
    if( ! (currentLevel->isFree(y, x) )  && 
        currentLevel->isVisible(y, x) ) {

            currentLevel->setVisible(y, x, false );

            score = currentLevel->getScore(y, x);

            if( score >= 0 )
                bonus += score;

            else if( score < malus )
                    malus = score;
    }

    if( y <= 0 )
        y = currentLevel->getLength();

    // Up-Sx
    if( ! (currentLevel->isFree(y - 1, x - 1) )  && 
        currentLevel->isVisible(y - 1 , x - 1) ) {

            currentLevel->setVisible(y - 1, x - 1, false );

            score = currentLevel->getScore(y - 1, x - 1);            

            if( score >= 0 )
                    bonus += score;

                else if( score < malus )
                        malus = score;
    }


    // Up-Dx
    if( ! (currentLevel->isFree(y - 1, x + 1) )  && 
        currentLevel->isVisible(y - 1 , x + 1) ) {

            currentLevel->setVisible(y - 1, x + 1, false );

            score = currentLevel->getScore(y - 1, x + 1);

            if( score >= 0 )
                    bonus += score;

                else if( score < malus )
                        malus = score;
    }

    y = c.getPosition().y;
    if( y >= currentLevel->getLength() - 1)
        y = -1;

    // Down-Dx
    if( ! (currentLevel->isFree(y + 1, x + 1) )  && 
        currentLevel->isVisible(y + 1 , x + 1) ) {

            currentLevel->setVisible(y + 1, x + 1, false );

            score = currentLevel->getScore(y + 1, x + 1);

            if( score >= 0 )
                    bonus += score;

                else if( score < malus )
                        malus = score;
    }

    // Down-Sx
    if( ! (currentLevel->isFree(y + 1, x - 1) )  && 
        currentLevel->isVisible(y + 1 , x - 1) ) {

            currentLevel->setVisible(y + 1, x - 1, false );

            score = currentLevel->getScore(y + 1 , x - 1);

            if( score >= 0 )
                    bonus += score;

                else if( score < malus )
                        malus = score;
    }

    return malus + bonus; 
    
}

/*
void game::forwardNewLevel(int s){
    c = car();
    currentLevel -> next = new level(s, HEIGHT_TRACK, currentLevel );
    currentLevel = currentLevel -> next;
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
}
*/

void game::NewLevel(int s, bool b){
    if(b){
        currentLevel -> next = new level(s, HEIGHT_TRACK + (s*5), currentLevel, b );
        currentLevel = currentLevel -> next;
        }
    else{
        currentLevel -> prev = new level(s, HEIGHT_TRACK, currentLevel, b );
        currentLevel = currentLevel -> prev;
    }
    c = car(currentLevel->getLength() - 2, 23);
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
}

void game::forwardLevel(){  
    currentLevel = currentLevel -> next;
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
    c = car(currentLevel->getLength() - 2, 23);
}

void game::backLevel(){
    currentLevel = currentLevel -> prev;
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
    c = car(currentLevel->getLength() - 2, 23);
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