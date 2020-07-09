#include <iostream>
#include <ncurses.h>
using namespace std;

#ifndef scorestage_H
#define scorestage_H

class scorestage{

    protected:
        int score;
        int record;
        int lowest;
        int lastLevel;
        WINDOW *scoreWin;

    public:
        scorestage(int);
        
        // Add x point to score
        void addScore(int);

        // Print UI
        void printScoreText();
        void printScoreStage();

        // Getters
        int getLastLevel ();
        int getLowestScore();
        int getMaxScore();
        int getScore();
        int getStage();
        
        // Setters
        void setlastLevel();

};


#endif