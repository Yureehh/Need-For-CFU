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
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    */

    //Starting the game
    mvprintw(21, 11, "Press Any Key To Start!");
    getch();
    erase();
    //Stamp the UI and the car
    layout l = layout();
    l.stampaUI();
    l.stampaScore();
    scorestage s = scorestage(2300);
    s.PrintScoreStage();
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

       
    car c = car(38,23,40,23,39,24,38,25,40,25); //never cancellare pls 
    c.stampa();
    refresh();
    int ch ='7';
    bool spostamento = true, loss = false;
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

    if(loss){
        erase();
        mvprintw(21, 11, "Take the L!");
        getch();
    }

    endwin();

    return 0;
}