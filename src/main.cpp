#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "layout.h"
#include "entities\car.h"

int main(int argc, char *argv[]){

    // _ Setup ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    
    //Starting the game
    mvprintw(21, 11, "Press Any Key To Start!");
    getch();
    erase();
    //Stamp the UI and the car
    layout l = layout();
    l.stampa_UI();
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
    while(ch != ' '){
        ch= getch();
        if(ch == 'a' || ch == KEY_LEFT){
            c.clean();
            c.sinistra();
        }   
        if(ch == 'd' || ch == KEY_RIGHT){
            c.clean();
            c.destra();
        }
        c.stampa();
        refresh();
    }

    endwin();

    return 0;
}