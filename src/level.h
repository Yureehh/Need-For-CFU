#include <iostream>
#ifdef __linux__ 
    #include "entities/obstacle.h"
#else
    #include "entities\obstacle.h"
#endif
using namespace std;

#ifndef LEVEL_H
#define LEVEL_H

class level{
protected:
        struct ptrObstacle{
            bool visible;
            obstacle *obst;
        };
        int stage;
        int length;
        obstacle oneXone;
        obstacle boost;
        ptrObstacle** track;
public:
        level *prev;
        level *next;

        level();
        level(int, int, level*, bool);
        
        int getStage();

        int getLength();
        
        bool isFree(int, int);

        void setVisible(int, int, bool);

        bool isVisible(int, int);

        const char* getChar(int, int);

        int getScore(int, int);

        int getColor(int, int);
        
        

};

#endif                                       