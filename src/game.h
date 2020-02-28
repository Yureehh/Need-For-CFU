#include <iostream>
#include <ncurses.h>
#include <map>
#include "level.h"
#include "scorestage.h"
#ifdef __linux__ 
    #include "entities/car.h"
#else
    #include "entities\car.h"
#endif

using namespace std;

// # User Interface geometry (UI)
const char height_UI = 42;
const char width_UI = 80;

const char height_Track = 40; // 0-39      centro 19
const char width_Track = 47; //0-46        centro 24


#ifndef GAME_H
#define GAME_H

class game {

    protected:
        int  start_Track = 0; //linea in cui starta la pista
        level *current_Level;
        car c;

    public:
        //Initialize the game
        game();
        
        //prints the game
        void stampaUI();

        //clears the Track
        void clean();

        //Prints the words
        void stampaScore();

        // Car controls and Render
        void stampaCar();

        void cleanCar();

        bool sinistraCar();

        bool destraCar();

        int hit(int);

        int calcScore(chtype *);

        //Downs the obstacler of 1 line
        void downTrack();

};

#endif