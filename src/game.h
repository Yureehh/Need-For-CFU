#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "level.h"
#include "scorestage.h"
#include "math.h"
#include "utilities.h"
#ifdef __linux__ 
    #include "entities/car.h"
#else
    #include "entities\car.h"
#endif

using namespace std;

// # User Interface geometry (UI)
const char HEIGHT_UI = 42;
const char WIDTH_UI = 80;

const char HEIGHT_TRACK = 40; // 0-39      centro 19
const char WIDTH_TRACK = 47; //0-46        centro 23


#ifndef GAME_H
#define GAME_H

class game {

    protected:
        int  start_Track; //linea in cui starta la pista
        level *currentLevel;
        car c;


    public:
        //Initialize the game
        game();
        
        //prints the game
        void printUI();

        void clearLevel();

        void clearLine();

        //Prints the words
        void printScore();

        // Car controls and Render
        void carPrint();

        void carClean();

        bool carLeft();

        bool carRight();

        void carForward();

        void printTrack();

        //Downs the obstacler of 1 line
        void downTrack();

        int collisionCheck(int, int);

        int collisions();

        void forwardNewLevel(int);

        void forwardLevel();

        void backLevel();

        bool loss(scorestage);

};

#endif