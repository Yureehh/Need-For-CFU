#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "game.h"
#include "level.h"
#include "utilities.h"

// ! Usare mvinch(x,y) per sapere che char è fatto vedere in x,y

int main(int argc, char *argv[]){

    // _ Setup ncurses
    initscr();
    start_color();

    use_default_colors();

    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);

    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);

    //Starting the game
    mvprintw(21, 11, "Press Key To Start!");
    while(!kbhit());
    erase();

    //Print the UI
    game g = game();
    g.stampaUI();
    g.stampaScore();

    //inizialize points
    scorestage s = scorestage(901);
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
    //g.primaStampa();
    g.stampaCar();
    refresh();

    bool loss = false, dannoMuro = true;
    int timer =0;
    char ch=' ';


    //the game itself, for now u can only move the car
    while(ch != 113 && !loss){
        
        usleep(3125);

        if(kbhit()){
            ch = getch();
            if(ch == 'a' || ch == 68){
                g.cleanCar();
                dannoMuro = g.sinistraCar();
            }  

            if(ch == 'd' || ch == 67){
                g.cleanCar();
                dannoMuro = g.destraCar();
            }

            s.AddScore(g.collisioni());
           
            if(!dannoMuro)
                s.SubScore(500);
            dannoMuro = true;

            
            if(s.GetScore() <= 0)
                loss = true;

        }

        if(timer<=0){
            g.downTrack();
            g.avantiCar();
            
            s.AddScore(g.collisioni() + 25);

            timer = 100; //800
             
        } else
            timer--;
            

        if(s.GetStage() != s.Getlevelprec()){
            g.clearLevel();
            erase();
            g.stampaUI();

            if(s.GetStage() > s.Getlevelprec()){
                if(s.GetScore() == s.GetMaxScore() )
                    g.forwardNewLevel(s.GetStage());
                else
                    g.forwardLevel();
            }

            else{
                g.backLevel();
            }

            s.setLevelPrec();
        }
        else
            g.clearLine();
        



         //inserire animazione cambio livello w la figa O:



        s.PrintScoreStage();
        g.stampaCar();    
        refresh();
        if(s.GetScore() <= 0)
            loss = true;
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
