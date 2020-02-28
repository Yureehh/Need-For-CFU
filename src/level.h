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

        int length;
        // this->prev->next = this;
        level *prev;
        level *next;
        obstacle oneXone;
        obstacle boost;
        obstacle twoXtwo;

    public:
        ptrObstacle** track;
        
        level(int, int, level*);
        level();
        
        bool is_Free(int, int);
        const char* get_Char(int, int);
        
        int get_Length();
        
        void generateObstacles();

};

#endif                                       