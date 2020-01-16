#include <ncurses.h>
#include <iostream>
#include "layout.h"


int main(int argc, char *argv[]){

    // _ Setup ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    
    // _ Stamp the layout and
    layout l = layout();
    l.stampa_UI();

    printw("\npremi spazio per iniziare");
    
    refresh();
    getch();
    
    endwin();

    return 0;
}