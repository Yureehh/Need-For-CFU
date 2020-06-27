#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "game.h"


void startGame(){
    
    //inizialize points and game
    scorestage s = scorestage(4900);
    game g = game( s.getStage() );

    //Print the UI
    g.printUI();
    s.printScoreText();
    s.printScoreStage();


    //countdown
    mvprintw(21, 22, "Ready");
    refresh();
    sleep(1);
    mvprintw(21, 22, " Set ");
    refresh();
    sleep(1);
    mvprintw(21, 22, " Go! ");
    refresh();
    sleep(1);

    flushinp(); // Discard any keyboard input

    //prints the starting Track with the car and obstacles
    g.printTrack();
    g.carPrint();
    refresh();

    int timer = 0;
    char ch=' ';


    //the game itself, for now u can only move the car
    while(ch != 113){
        
        //number of milliseconds the game gets paused every cicle
        usleep(3125);

        //checks if lateral displacements collides with walls or obstacles
        if(kbhit()){
            ch = tolower(getch()); // Avoids mis match with 'A' and 'a'

            switch(ch){
            
                case 'a':
                    g.carClean();
                    if(!g.carLeft())
                        s.addScore(-1000);
                    break;
            
                case 'd':
                    g.carClean();
                    if(!g.carRight())
                        s.addScore(-1000);
                    break;
                
                case 27:
                    g.pause();
                    g.printTrack();
                    break;
            }

            s.addScore( g.collisions() );

            if(s.getScore() <= 0)
                if( g.loss(s) )
                    break;
        }

        //if the right amount of seconds has passed the obstacles are lowered by 1 line and collisions are checked
        if(timer<=0){
            g.downTrack();
            
            s.addScore(g.collisions() + 10 ); // + 25);

            timer = g.clock(s.getMaxScore()/1000); //!960 fa 3 secondi di pausa  

             
        } else
            timer--;    //combination of timer and usleep creates the clock of the map's sliding

        //checks if u have enough points to swap level
        if(s.getStage() != s.getLastLevel()){
            
            g.clearLevel();
            g.carPrint();
            
            if(s.getStage() > s.getLastLevel()){
                if(s.getScore() == s.getMaxScore() )
                    g.NewLevel(s.getStage(), true );
                else
                    g.forwardLevel();
            }

            else{
                if(s.getScore() == s.getLowestScore() ){
                    g.NewLevel(s.getStage(), false );
                }

                else
                    g.backLevel();
            }
            // Reprint everything inside the trackWindow
            g.printUI();
            g.printTrack();
            s.printScoreText();

            s.setlastLevel();
        }
        else
            g.clearLine();


        s.printScoreStage();
        g.carPrint();
        refresh();
        if( g.loss(s) )
            break;
    }

    erase();

}

int main(int argc, char *argv[]){

    // _ Setup ncurses
    setlocale( LC_ALL, "" );
    initscr();

    // Setup Colors
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);

    init_pair(3, COLOR_MAGENTA, -1);
    init_pair(4, COLOR_CYAN, -1);

    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Start the game, quit only if when specified
    while(mainMenu())
        startGame();  

    endwin();

}
