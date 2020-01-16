#include <iostream>
#include <ncurses.h>
using namespace std;


// # User Interface geometry (UI)
const char larghezza = 80;
const char altezza = 42;

const char larghezza_layout = 33;
const char altezza_layout = 40;


class layout{

    protected:

        char UI[altezza][larghezza];
        char mappa[altezza_layout][larghezza_layout];

    public:

        layout(){
            for(int i = 0; i< altezza;i++) {
                for (int j = 0; j < larghezza; j++) {
                        if(i == 0 || i == altezza-1) {
                            UI[i][j] = '-';
                        }
                        else{
                            if(j == 0 || j == larghezza -1)
                                UI[i][j] = '|';
                            else if(j == 1 || j == larghezza_layout + 2 )
                                UI[i][j] = '#';
                            else
                                UI[i][j] =' ';
                        }
                    }
                }
            }


        void stampa_UI(){
            for(int i = 0; i< altezza;i++) {
                for (int j = 0; j < larghezza; j++) {
                    mvprintw(i, j, new char(UI[i][j]));
                }
                printw("\n");
            }
        }
        
};


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