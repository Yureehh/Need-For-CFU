#include "layout.h"

layout::layout(){
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

void layout::stampa_UI(){
    for(int i = 0; i< altezza;i++) {
        for (int j = 0; j < larghezza; j++) {
            mvprintw(i, j, new char(UI[i][j]));
        }
        printw("\n");
    }
}
