#include "game.hpp"

// Check if user pressed any key
bool kbhit()
{
    int ch = getch();
    if (ch != ERR) {
        ungetch(ch);
        return true;
    } else 
        return false;
}

// Initialize the level, the car and the track
game::game(int s){
    currentLevel = new level(s, HEIGHT_TRACK + 10, NULL, true);
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

void game::printUI(){

    box(uiWin, '|', '-');
    wborder(trackWin, '#', '#', ' ', ' ', '#', '#', '#', '#');
    
    wrefresh(uiWin);
    wrefresh(trackWin);
}

// Prints the visible section of the track
void game::printTrack(){

    int r = start_Track;

    /*
    ** r is used to access to the matrix track[][]
    ** i is used to stamp in the correct place on the terminal
    */

    for (int i = 0; i < HEIGHT_TRACK; i++){
        for (int j = 0; j < WIDTH_TRACK; j++){
            // Loop when u finish the map
            if ( r >= currentLevel->getLength() )
                r = 0;
            // Stamp the CHAR only when there is an obstacle -> !isFree
            if ( currentLevel->isFree(r, j) )
                mvwprintw(trackWin, i, j+1, " " );
            else{
                // If the obstacle is visible, stamp with the corresponding color
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

// Scroll down the track
void game::downTrack(){

    start_Track --;

    if( start_Track < 0)
        start_Track = currentLevel->getLength() - 1;

    printTrack();
    carForward();
}

// Reset the line who just exited fromt the visible part of the track to visible
void game::clearLine(){
    int i = (c.getY() + 2) % currentLevel->getLength();
    for(int j=0; j<WIDTH_TRACK; j++){
        if(!currentLevel->isFree(i,j))
                currentLevel->setVisible(i,j, true);
    }
}

void game::carPrint(){
    c.stampa();
}

// Erases the car
void game::carClean(){
    c.clean();
}

// Moves the car to the left, not printing it yet
bool game::carLeft(){
    // Move only if isn't on the map's left border
    if ( c.getX() > 1 ){
        c.move( 0, -1 );
        return true;
    } else
        return false;
}

// Moves the car to the right, not printing it yet
bool game::carRight(){
    // Move only if isn't on the map's right border
    if ( c.getX() < 45 ){
        c.move( 0, +1);
        return true;
    } else
        return false;
}

// Moves the car 1 row up
void game::carForward(){
    if(c.getY() > 0)
        c.move( -1, 0);
    else
        c.move(HEIGHT_TRACK - 1, 0);
}

// Check if there's an obstacle in a certain point of the track
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

// Calls collisionsCheck in every part of the car
int game::collisions(){
    
    // Inizialized as pilot's coordinates
    int y = c.getY();
    int x = c.getX();

    int tot=0;

    // Pilot's collision
    tot = collisionCheck(y, x);

    // To avoid bugs when pilot is on the last line of the track and the forward wheels on the first new one
    if( y <= 0 )
        y = currentLevel->getLength();

    // Forward wheels collisions     
    tot += collisionCheck(y-1, x-1) + collisionCheck(y-1, x+1);

    // To avoid bugs when pilot is on the first line of the track and the back wheels on the last new one
    y = c.getY();
    if( y >= currentLevel->getLength() - 1)
        y = -1;
    
    // Back wheels collisions
    tot+= collisionCheck(y+1, x-1) + collisionCheck(y+1, x+1);
    
    return tot;
    
}

// Creates a new level, next or previous based on the boolean
void game::newLevel(int s, bool b){
    if(b){
        currentLevel -> setNext(new level(s, HEIGHT_TRACK + 10, currentLevel, b ));
        forwardLevel();
    }
    else{
        currentLevel -> setPrev(new level(s, HEIGHT_TRACK + 10, currentLevel, b ));
        backLevel();
    }
}

// Resets the current level setting all obstacles to visible except for the first 10 lines from the bottom
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

// Goes to the next level
void game::forwardLevel(){
    currentLevel = currentLevel -> getNext();

    werase(pauseWin);
    box(pauseWin, 0, 0);
    wattron(pauseWin, COLOR_PAIR(2));
    mvwprintw(pauseWin, 2, 4, "LEVEL %d", currentLevel->getStage());
    wattroff(pauseWin, COLOR_PAIR(2));
    wrefresh(pauseWin);

    sleep(3);

    changeLevel();
}

// Goes to the previous level
void game::backLevel(){
    currentLevel = currentLevel -> getPrev();

    werase(pauseWin);
    box(pauseWin, 0, 0);
    wattron(pauseWin, COLOR_PAIR(1));
    mvwprintw(pauseWin, 2, 4, "LEVEL %d", currentLevel->getStage());
    wattroff(pauseWin, COLOR_PAIR(1));
    wrefresh(pauseWin);

    sleep(3);

    changeLevel();
}

// Reset the car and track positions
void game::changeLevel(){
    start_Track = currentLevel->getLength() - HEIGHT_TRACK;
    c = car(currentLevel->getLength() - 2, 23);
    werase(trackWin);
    wrefresh(trackWin);
    flushinp();
}

// Timer for the track movement
int game::clock(int difficulty){
    return 64+(100/pow(1.4,difficulty));
}

// Pause the game and stamp "Pause" window
void game::pause(){
    int c;

    werase(pauseWin);
    box(pauseWin, 0, 0);
    mvwprintw(pauseWin, 2, 5, "PAUSE");
    wrefresh(pauseWin);

    while((c = wgetch(pauseWin)) != 27);

}

// Checks if you lost
bool game::loss(scorestage s){
    if(s.getScore() <= 0){
        
        werase(trackWin);
        printUI();
        wrefresh(trackWin);

        mvprintw(21, 17, "Take the L !");
        mvprintw(23, 5, "Your record this run has been %d points!", s.getMaxScore());
        
        refresh();

        sleep(1);
        flushinp(); // Discard any keyboard input
        
        while(!kbhit());
        return true;
    }
    return false;
}

