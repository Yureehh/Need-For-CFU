#include <iostream>
#include <ncurses.h>
using namespace std;

const char larghezza = 40;
const char altezza = 30;

class mappa{

protected:
    char layout[altezza][larghezza];

public:

    mappa(){
        for(int i=0; i< altezza;i++) {
            for (int j = 0; j < larghezza; j++) {
                    if(i==0 || i== altezza -1) {
                    layout[i][j] = '-';
                }
                    else{
                        if(j==0 || j == larghezza -1)
                            layout[i][j] = '|';
                        else if(j==1 || j==27)
                            layout[i][j] = '#';
                        else
                            layout[i][j] =' ';
                    }
                }
            }
        }


    void stampa(){
        for(int i=0; i< altezza;i++) {
            for (int j = 0; j < larghezza; j++) {
                printw( new char(layout[i][j]) );
            }
            printw("\n");
        }
    }


};


int main(){

    initscr();
    mappa pista = mappa();
    pista.stampa();
    printw("\npremi spazio per iniziare");
    refresh();
    getch();
    endwin();

    return 0;
}