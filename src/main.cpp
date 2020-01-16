#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "layout.h"
#include "car.h"

int main(int argc, char *argv[]){

    // _ Setup ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    
    //Starting the game
    mvprintw(0, 0, "premi un tasto per iniziare a giocare");
    getch();
    erase();
    mvprintw(0, 0, "Il gioco inizia fra 3");
    refresh();
    sleep(1);
    mvprintw(0, 0, "Il gioco inizia fra 2");
    refresh();
    sleep(1);
    mvprintw(0, 0, "Il gioco inizia fra 1");
    refresh();
    sleep(1);

    //Stamp the UI and the car
    layout l = layout();
    l.stampa_UI();   
    car c = car(38,23,40,23,39,24,38,25,40,25);
    c.stampa();
    refresh();
    int ch = getch();
    while(ch != ' '){
        if(ch == 'a' || ch == KEY_LEFT)
            c.sinistra();
        if(ch == 'd' || ch == KEY_RIGHT)
            c.destra();
        c.stampa();
        refresh();
    }

    endwin();

    return 0;
}