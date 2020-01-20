#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "layout.h"
#include "scorestage.h"
#include "entities\car.h"


/*
#ifdef __linux__ 
    #include "entities/car.h"
#elif _WIN32
    #include "entities\car.h"
#else
    cout << "Hai un OS sfigato cosa ti posso dire"
#endif
*/

int main(int argc, char *argv[]){

    // _ Setup ncurses
    initscr();
    noecho();
    curs_set(FALSE);

    /*
    unlucky tentativo di far rosso se prendi danno
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    */

    //Starting the game
    mvprintw(21, 11, "Press Any Key To Start!");
    getch();
    erase();

    //Print the UI 
    layout l = layout();
    l.stampaUI();
    l.stampaScore();

    //Print obstacles
    l.stampaOstacoli();

    //inizialize points
    scorestage s = scorestage(1);
    s.PrintScoreStage();
    //countdown
    mvprintw(21, 24, "3");
    refresh();
    sleep(1);
    mvprintw(21, 24, "2");
    refresh();
    sleep(1);
    mvprintw(21, 24, "1");
    refresh();
    sleep(1);
    mvprintw(21, 24, " ");

    //prints the car
    car c = car(38,23,40,23,39,24,38,25,40,25); //should fix the default constructor later
    c.stampa();
    refresh();
    int ch ='7';
    bool spostamento = true, loss = false;
    
    //the game itself, for now u can only move the car
    while(ch != ' ' && !loss){
        
        ch= getch();
        if(ch == 'a' || ch == 68){
            c.clean();
            spostamento = c.sinistra();
        }   
        if(ch == 'd' || ch == 67){
            c.clean();
            spostamento = c.destra();
        }
        //if u hit something trying to move u lose points
        if(!spostamento){
            spostamento = true;
            s.SubScore(500);
            if(s.GetScore() <= 0){
                loss = true;
            }
        }
        
        

        s.PrintScoreStage();
        c.stampa();
        refresh();
    }

    //2 possible endings: u lost or u pressed spacebar
    if(loss){
        erase();
        mvprintw(21, 11, "Take the L!");
        getch();
    }

    endwin();

    return 0;
}