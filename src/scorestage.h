#include <iostream>
#include <ncurses.h>
using namespace std;

#ifndef SCORESTAGE_H
#define SCORESTAGE_H

class scorestage{
protected:
    int score;
    int stage;
public:
   scorestage(int);
   int GetScore();
   int GetStage();
   int AddScore(int);
   int SubScore(int);
   void PrintScoreStage();
};


#endif