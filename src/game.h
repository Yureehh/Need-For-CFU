#include <unistd.h>
#include "level.h"
#include "scorestage.h"
#include "math.h"
#ifdef __linux__ 
    #include "entities/car.h"
#else
    #include "entities\car.h"
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
        //Downs the obstacler of 1 line
        void downTrack();

        void clearLevel();

        void clearLine();
        // Car controls and Render
        void carPrint();

        void carClean();

        bool carLeft();

        bool carRight();

        void carForward();

        int collisionCheck(int, int);

        int collisions();

        void newLevel(int, bool);

        void forwardLevel();

        void backLevel();

        void changeLevel();

        int clock(int);
        
        void pause();

        bool loss(scorestage);
    


};

#endif