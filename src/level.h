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
        obstacle oneXone;
        obstacle boost;
        obstacle twoXtwo;
        ptrObstacle** track;

    public:
        
        level *prev;
        level *next;
        
        level(int, int, level*);
        level();
        
        bool isVisible(int, int);

        void hasHit(int, int);

        bool is_Free(int, int);

        const char* get_Char(int, int);

        int get_Score(int , int);
        
        int get_Length();
    
        void setNext(int, int, level*);

};

#endif                                       