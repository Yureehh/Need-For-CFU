#include <iostream>
#include <ncurses.h>
#include "level.h"
#include "scorestage.h"

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
        char Track[height_Track][width_Track];
        int  start_Track; //linea in cui starta la pista

    public:
        //Initialize the game
        game();
        
        //prints the game
        void stampaUI();

        //clears the Track
        void clean();

        //Prints the words
        void stampaScore();

        //Prints test Track
        //void stampaOstacoli();

        //creates the obstacles
        void generateObstacles();


        //Downs the obstacler of 1 line
        void downTrack();

};

#endif