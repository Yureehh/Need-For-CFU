#include "game.h"
#include "math.h"

//Initialize the game
game::game(int s){
    currentLevel = new level(s, HEIGHT_TRACK, NULL, true);
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
    c = car(currentLevel->getLength() - 2, 23);

    uiWin = newwin(HEIGHT_UI, WIDTH_UI, 0, 0);
    trackWin = newwin(HEIGHT_TRACK, WIDTH_TRACK + 2, 1, 1);

    int y,x;
    getmaxyx(trackWin, y, x);
    pauseWin = derwin(trackWin, 5, 15, y/2 - 2, x/2 - 8);

    refresh();

    printUI();

}


void game::clearLevel(){  
    for (int i = 0; i < currentLevel->getLength()-1; i++){
        for (int j = 0; j < WIDTH_TRACK; j++){
            if(i<=currentLevel->getLength()-1 && i> currentLevel->getLength()-10)
                currentLevel->setVisible(i,j,false);
            else if(!currentLevel->isFree(i,j))
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

    box(uiWin, '|', '-');
    wborder(trackWin, '#', '#', ' ', ' ', '#', '#', '#', '#');
    
    wrefresh(uiWin);
    wrefresh(trackWin);

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

    for (int i = 0; i < HEIGHT_TRACK; i++){
        for (int j = 0; j < WIDTH_TRACK; j++){
            // Loop when u finish the map
            if ( r >= currentLevel->getLength() )
                r = 0;
            // Stamp the CHAR only when there is an obstacle -> !isFree
            if ( currentLevel->isFree(r, j) )
                mvwprintw(trackWin, i, j+1, " " );
            else{
                if ( currentLevel->isVisible(r, j) ){
                    wattron(trackWin, COLOR_PAIR(currentLevel->getColor(r, j)));
                    mvwprintw(trackWin, i, j+1, currentLevel->getChar(r, j) );
                    wattroff(trackWin, COLOR_PAIR(currentLevel->getColor(r, j)));
                }
            }
        }

        r++;

    }

    wrefresh(trackWin);

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
       
    int malus=0, bonus=0, score=0;


    if( ! (currentLevel->isFree(y, x) )  && 
        currentLevel->isVisible(y, x) ) {

            currentLevel->setVisible(y, x, false);

            score = currentLevel->getScore(y, x);

            if( score >= 0 )
                bonus += score;

            else if( score < malus )
                    malus = score;
    }
    
    
    return malus + bonus;   
    
}


int game::collisions(){
    
    //inizialized as pilot's coordinates
    int y = c.getPosition().y;
    int x = c.getPosition().x;

    int tot=0;

    //pilot's collision
    tot = collisionCheck(y, x);

    //to avoid bugs when pilot is on the last line of the track and the forward wheels on the first new one
    if( y <= 0 )
        y = currentLevel->getLength();

    //forward wheels collisions     
    tot += collisionCheck(y-1, x-1) + collisionCheck(y-1, x+1);

    //to avoid bugs when pilot is on the first line of the track and the back wheels on the last new one
    y = c.getPosition().y;
    if( y >= currentLevel->getLength() - 1)
        y = -1;
    
    //back wheels collisions
    tot+= collisionCheck(y+1, x-1) + collisionCheck(y+1, x+1);
    
    return tot;
    
}

void game::NewLevel(int s, bool b){
    if(b){
        currentLevel -> next = new level(s, HEIGHT_TRACK + (s*10), currentLevel, b );
        forwardLevel();
    }
    else{
        currentLevel -> prev = new level(s, HEIGHT_TRACK, currentLevel, b );
        backLevel();
    }

}

void game::forwardLevel(){
    currentLevel = currentLevel -> next;

    werase(pauseWin);
    box(pauseWin, 0, 0);
    wattron(pauseWin, COLOR_PAIR(2));
    mvwprintw(pauseWin, 2, 4, "LEVEL %d", currentLevel->getStage());
    wattroff(pauseWin, COLOR_PAIR(2));
    wrefresh(pauseWin);

    sleep(3);

    changeLevel();
}

void game::backLevel(){
    currentLevel = currentLevel -> prev;

    werase(pauseWin);
    box(pauseWin, 0, 0);
    wattron(pauseWin, COLOR_PAIR(1));
    mvwprintw(pauseWin, 2, 4, "LEVEL %d", currentLevel->getStage());
    wattroff(pauseWin, COLOR_PAIR(1));
    wrefresh(pauseWin);

    sleep(3);

    changeLevel();
}

void game::changeLevel(){
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
    c = car(currentLevel->getLength() - 2, 23);
    werase(trackWin);
    wrefresh(trackWin);
}

void game::pause(){
    int c;

    werase(pauseWin);
    box(pauseWin, 0, 0);
    mvwprintw(pauseWin, 2, 5, "PAUSE");
    wrefresh(pauseWin);

    while((c = wgetch(pauseWin)) != 27);

}

bool game::loss(scorestage s){
    if(s.getScore() <= 0){
        
        werase(trackWin);
        printUI();
        wrefresh(trackWin);

        mvprintw(21, 17, "Take the L!");
        mvprintw(23, 5, "Your record this run has been %d points!", s.getMaxScore());
        while(!kbhit());
        return true;
    }
    return false;
}

int game::clock(){
    return 272+(190/pow(1.6,currentLevel->getStage()));
}