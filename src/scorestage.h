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
    int lowest;
    int lastLevel;
    WINDOW *scoreWin;
public:
    //constructor to inizialize points
   scorestage(int);
    //getter for the score
    int getScore();
    //getter for the stage
    int getStage();
    //Record of the run
    int getMaxScore();
    //Lowest record
    int getLowestScore();
    //add points
    void addScore(int);
    //prints score and level
    void printScoreText();
    void printScoreStage();

    void setlastLevel();
    
    int getLastLevel ();
};


#endif