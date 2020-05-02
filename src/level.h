#include <iostream>
#ifdef __linux__ 
    #include "entities/obstacle.h"
#else
    #include "entities\obstacle.h"
#endif

#ifndef LEVEL_H
#define LEVEL_H

using namespace std;

class level{

    protected:
        struct ptrObstacle{
            bool visible;
            obstacle *obst;
        };

        int stage;
        int length;
        // this->prev->next = this;
        obstacle oneXone;
        obstacle boost;
        obstacle twoXone;
        ptrObstacle** track;

    public:
        
        level *prev;
        level *next;
        
        level(int, int, level*, bool);
        level();
        
        bool isFree(int, int);

        void setVisible(int, int, bool);

        bool isVisible(int, int);

        const char* getChar(int, int);

        int getScore(int, int);

        int getColor(int, int);
        
        int getStage();

        int getLength();

};

#endif                                       