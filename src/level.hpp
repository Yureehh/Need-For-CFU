#include <iostream>
#ifdef __linux__ 
    #include "entities/obstacle.hpp"
#else
    #include "entities\obstacle.hpp"
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
        level *prev, *next;

    public:
        level();
        level(int, int, level*, bool);
        
        bool isFree(int, int);
        bool isVisible(int, int);

        // Getters
        const char* getChar(int, int);
        int getColor(int, int);
        int getLength();
        level *getNext();
        level *getPrev();
        int getStage();
        int getScore(int, int);

        // Setters
        void setNext(level *next);
        void setPrev(level *prev);
        void setVisible(int, int, bool);

};

#endif                                       