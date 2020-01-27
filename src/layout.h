#include <iostream>
#include <ncurses.h>
#include "scorestage.h"

#ifdef __linux__     
    #include "entities/obstacle.h"
    #include "entities/obstacle1x2.h"
    #include "entities/obstacle2x2.h"
#elif _WIN32    
    #include "entities\obstacle.h"
    #include "entities\obstacle1x2.h"
    #include "entities\obstacle2x2.h"
#endif
using namespace std;

// # User Interface geometry (UI)
const char height_UI = 42;
const char width_UI = 80;

const char height_map = 40; // 0-39      centro 19
const char width_map = 47; //0-46        centro 24


#ifndef LAYOUT_H
#define LAYOUT_H

class layout {

    protected:
        char UI[height_UI][width_UI];
        char map[height_map][width_map];
        int  start_map; //linea in cui starta la mappa

    public:
        //Initialize the layout
        layout();
        
        //prints the layout
        void stampaUI();

        //clears the map
        void clean();

        //Prints the words
        void stampaScore();

        //Prints test map
        //void stampaOstacoli();

        //creates the obstacles
        void generateObstacles();


        //Downs the obstacler of 1 line
        void downMap();

};

#endif