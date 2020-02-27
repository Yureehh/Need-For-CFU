#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "game.h"
#include "level.h"
#include "utilities.h"

// ! Usare mvinch(x,y) per sapere che char è fatto vedere in x,y
//bool urto();

int main(int argc, char *argv[]){

    // _ Setup ncurses
    initscr();
    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    /*
    unlucky tentativo di far rosso se prendi danno
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    */

    //Starting the game
    mvprintw(21, 11, "Press Key To Start!");
    while(!kbhit());
    erase();

    //Print the UI
    game g = game();
    g.stampaUI();
    g.stampaScore();
    

    //inizialize points
    scorestage s = scorestage(0);
    s.PrintScoreStage();
    //countdown
    mvprintw(21, 24, "3");
    refresh();
    sleep(1);
    mvprintw(21, 24, "2");
    refresh();
    sleep(1);
    mvprintw(21, 24, "1");
    refresh();
    sleep(1);
    mvprintw(21, 24, " ");
    

    //prints the starting Track with the car and obstacles
    g.downTrack();
    g.stampaCar();
    refresh();

    bool loss = false;
    int spostamento;
    char ch=' ';
    int timer = 0;
    int t;

    //the game itself, for now u can only move the car
    while(ch != 113 && !loss){
        spostamento = 0;
        usleep(6250);
        if(kbhit()){
            ch = getch();
            if(ch == 'a' || ch == 68){
                g.cleanCar();
                spostamento += g.hit(-1);
                g.sinistraCar();
            }   
            if(ch == 'd' || ch == 67){
                g.cleanCar();
                spostamento += g.hit(1);
                g.destraCar();
            }

        }

        if(timer<=0){
            g.downTrack();
            spostamento += g.hit(0);
            s.AddScore(20);
            timer = 50; //400 
        } else
            timer--;
            
        s.AddScore( spostamento );
        

        s.PrintScoreStage();
        if(s.GetScore() <= 0){
            loss = true;
        }

        g.stampaCar();    
        refresh();
    }

    //2 possible endings: u lost or u pressed spacebar
    if(loss){
        erase();
        mvprintw(21, 17, "Take the L!");
        mvprintw(23, 5, "Your record this run has been %d points!", s.GetMaxScore());
        while(!kbhit());

    }

    endwin();

    return 0;
}
