#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "layout.h"
#include "scorestage.h"
#include "utilities.h"


#ifdef __linux__ 
    #include "entities/car.h"
#elif _WIN32
    #include "entities\car.h"
#endif

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
    layout l = layout();
    l.stampaUI();
    l.stampaScore();



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
    

    //prints the starting map with the car and obstacles
    car c = car(38,23); //should fix the default constructor later
    l.downMap();
    c.stampa();
    refresh();

    bool spostamento = true, loss = false;
    // bool danno = (!spostamento);
    char ch=' ';
    int timer = 0;
    int t;

    //the game itself, for now u can only move the car
    while(ch != 113 && !loss){
        usleep(6250);
        if(kbhit()){
            ch = getch();
            if(ch == 'a' || ch == 68){
                c.clean();
                spostamento = c.sinistra();
            }   
            if(ch == 'd' || ch == 67){
                c.clean();
                spostamento = c.destra();
            }

        }

        if(timer<=0){
            l.downMap();
            s.AddScore(20);
            s.PrintScoreStage();
            timer = 50; //400 
        }
        else 
            timer--;

        //if u hit something trying to move u lose points
        //if(danno){
            if(!spostamento)
                s.SubScore(500);
            /*if(urto())
                s.SubScore(200);*/
            spostamento = true;
            if(s.GetScore() <= 0){
                loss = true;
            }
        //}

        c.stampa();    
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
