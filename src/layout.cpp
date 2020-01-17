#include "layout.h"

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

void layout::stampaUI(){
    for(int i = 0; i< height;i++) {
        for (int j = 0; j < width; j++) {
            mvprintw(i, j, new char(UI[i][j]));
        }
        printw("\n");
    }
}
void layout::stampaScore(){
    int score=0 ,level=1;
    mvprintw(20,58,"Stage: %d",level);
    mvprintw(22,58,"Score: %d",score);

}
