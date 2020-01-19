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
    //constructor to inizialize points
   scorestage(int);
   //getter for the score
   int GetScore();
    //add points
   int AddScore(int);
    //sub points
   int SubScore(int);
   //prints score and level
   void PrintScoreStage();
};


#endif