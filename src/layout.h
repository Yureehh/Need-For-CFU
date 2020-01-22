#include <iostream>
#include <ncurses.h>
#include "scorestage.h"
#include "entities\obstacle1x1.h"
#include "entities\obstacle1x2.h"
#include "entities\obstacle2x2.h"
using namespace std;

// # User Interface geometry (UI)
const char width = 80;
const char height = 42;

const char width_layout = 47; //0-46        centro 24
const char height_layout = 40; // 0-39      centro 19


#ifndef LAYOUT_H
#define LAYOUT_H

class layout {

    protected:
        char UI[height][width];
        char mappa[height_layout][width_layout];
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