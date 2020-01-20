#include "layout.h"

//Initialize the layout
layout::layout(){
    for(int i = 0; i< height; i++) {
        for (int j = 0; j < width; j++) {
                if(i == 0 || i == height-1) {
                    UI[i][j] = '-';
                }
                else{
                    if(j == 0 || j == width -1)
                        UI[i][j] = '|';
                    else if(j == 1 || j == width_layout + 2 )
                        UI[i][j] = '#';
                    else
                        UI[i][j] =' ';
                }
            }
        }
}

//prints the layout
void layout::stampaUI(){
    for(int i = 0; i< height;i++) {
        for (int j = 0; j < width; j++) {
            mvprintw(i, j, new char(UI[i][j]));
        }
        printw("\n");
    }
}

//Prints the words
void layout::stampaScore(){
    mvprintw(20,58,"Stage: ");
    mvprintw(22,58,"Score: ");

}

//Prints test map
void layout::stampaOstacoli(){
    int x, y;
    for(int i=1;i<47;i++){
        for(int j=3;j<37;j++){
            x=rand()%20;
            if(x == 1){
                y=rand()%7;
                if(y==1||y==2){
                    obstacle1x1 u(j,i);
                    u.stampa();
                    refresh();
                    j=j+3;
                }
                else if(y==4||y==5){
                    obstacle1x2 r(j,i, j+1, i+1);
                    r.stampa();
                    refresh();
                    j=j+6;
                }
                else if(y==6){
                    obstacle2x2 d(j,i, j, i+1, j-1, i, j-1, i+1);
                    d.stampa();
                    refresh();
                    j=j+9;
                }
            }
        }
    }
}

