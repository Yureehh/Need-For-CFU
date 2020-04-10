#include <iostream>
#include <ncurses.h>
using namespace std;

#ifndef SCORESTAGE_H
#define SCORESTAGE_H

class scorestage{
protected:
    int score;
    int stage;
    int record;
    int livelloprec;
public:
    //constructor to inizialize points
   scorestage(int);
    //getter for the score
    int GetScore();
    //getter for the stage
    int GetStage();
    //Record of the run
    int GetMaxScore();
    //add points
    void AddScore(int);
    //sub points
    void SubScore(int);
    //prints score and level
    void PrintScoreStage();
    //check the change of level
    int LevelChange();

    void setLevelPrec();
    
    int Getlevelprec ();
};


#endif