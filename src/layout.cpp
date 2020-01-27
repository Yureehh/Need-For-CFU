#include "layout.h"
#include <unistd.h>

//Initialize the layout
layout::layout(){
    start_map = 0;
    for(int i = 0; i< height_map; i++) {
        for (int j = 0; j < width_map; j++) {
                map[i][j] =' ';
        }
    }
    map[20][20]= 'K';

    for(int i = 0; i< height_UI; i++) {
        for (int j = 0; j < width_UI; j++) {
                if(i == 0 || i == height_UI-1) {
                    UI[i][j] = '-';
                }
                else{
                    if(j == 0 || j == width_UI -1)
                        UI[i][j] = '|';
                    else if(j == 1 || j == width_map + 2 )
                        UI[i][j] = '#';
                    else 
                        UI[i][j] =' ';
                }
            }
        }
}


//prints the layout
void layout::stampaUI(){
    for(int i = 0; i< height_UI;i++) {
        for (int j = 0; j < width_UI; j++) {
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

void generateObstacles();


//Downs the obstacles of 1 line
 void layout::downMap(){  
    int riga = start_map;

    for(int i = 0; i<height_map; i++){
        for(int j=0; j<width_map; j++){
            if(riga >= 40)
                riga = 0;
            if(i >=3 && i <40){
                mvprintw(i+1,j+2, new char(map[riga][j]) );
            }
        }
        riga++;
    }

    start_map--;
    if(start_map < 0){
        start_map=39;
    }

}
