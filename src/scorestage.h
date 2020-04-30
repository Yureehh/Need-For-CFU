#include <iostream>
#include <ncurses.h>
using namespace std;

#ifndef scorestage_H
#define scorestage_H

class scorestage{
protected:
    int score;
    int stage;
    int record;
    int lastLevel;
public:
    //constructor to inizialize points
   scorestage(int);
    //getter for the score
    int getScore();
    //getter for the stage
    int getStage();
    //Record of the run
    int getMaxScore();
    //add points
    void AddScore(int);
    //sub points
    void SubScore(int);
    //prints score and level
    void printScoreStage();
    //check the change of level
    int LevelChange();

    void setlastLevel();
    
    int getLastLevel ();
};


#endif