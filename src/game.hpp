#include <unistd.h>
#include "level.hpp"
#include "scorestage.hpp"
#include "math.h"
#ifdef __linux__ 
    #include "entities/car.hpp"
#else
    #include "entities\car.hpp"
#endif
using namespace std;

// # User Interface geometry (UI)
const int HEIGHT_UI = 42;
const int WIDTH_UI = 80;

const int HEIGHT_TRACK = 40;
const int WIDTH_TRACK = 47;

#ifndef GAME_H
#define GAME_H


bool kbhit();

class game {

    protected:
        int  start_Track; 
        WINDOW *uiWin, *trackWin, *pauseWin;
        level *currentLevel;
        car c;

    public:
        
        //Initialize the game
        game(int);
        
        //prints the game
        void printUI();
        void printTrack();
        void downTrack();
        void clearLine();

        // Car controls and Render
        void carPrint();
        void carClean();
        bool carLeft();
        bool carRight();
        void carForward();

        // Collision
        int collisionCheck(int, int);
        int collisions();

        // Level's section
        void newLevel(int, bool);
        void clearLevel();
        void forwardLevel();
        void backLevel();
        void changeLevel();

        // Extra UI        
        void pause();
        bool loss(scorestage);
    
        int clock(int);
};

#endif