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
