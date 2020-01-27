#include "game.h"
#include <unistd.h>

//Initialize the game
game::game(){

    start_Track = 0;
    for(int i = 0; i< height_Track; i++) {
        for (int j = 0; j < width_Track; j++) {
                Track[i][j] =' ';
        }
    }
    Track[20][20]= 'K';
}


//prints the game
void game::stampaUI(){

    for(int i = 0; i< height_UI; i++) {
        for (int j = 0; j < width_UI; j++) {
            if(i == 0 || i == height_UI-1) {
                mvprintw(i, j, new char('-'));
            }
            else {
                if(j == 0 || j == width_UI -1)
                    mvprintw(i, j, new char('|'));
                else if(j == 1 || j == width_Track + 2 )
                    mvprintw(i, j, new char('#'));
                else
                    mvprintw(i, j, new char(' ')); 
            }
        }
    }

}

//Prints the words
void game::stampaScore(){
    mvprintw(20,58,"Stage: ");
    mvprintw(22,58,"Score: ");

}

void generateObstacles();


//Downs the obstacles of 1 line
 void game::downTrack(){  
    int riga = start_Track;

    for(int i = 0; i<height_Track; i++){
        for(int j=0; j<width_Track; j++){
            if(riga >= 40)
                riga = 0;
            if(i >=3 && i <40){
                mvprintw(i+1,j+2, new char(Track[riga][j]) );
            }
        }
        riga++;
    }

    start_Track--;
    if(start_Track < 0){
        start_Track=39;
    }

}
