#include "scorestage.h"


//constructor to inizialize points
scorestage::scorestage(int s){
    score = s;
    record = lowest = score;
    lastLevel = getStage();
    scoreWin = newwin(3, 20, 20, 58);
    refresh();
}

//getter for the score
int scorestage::getScore(){
    return score;
}

int scorestage::getMaxScore(){
    return record;
}

int scorestage::getLowestScore(){
    return lowest;
}

//getter for the stage
int scorestage::getStage(){
    return score/1000 + 1;
}

int scorestage::getLastLevel(){
    return lastLevel;
}

void scorestage::setlastLevel(){
    lastLevel = getStage();
}

//add points
void scorestage::addScore(int x){
    score = score + x;
    if(score > record)
        record = score;
    if(score < lowest)
        lowest = score;
}

//Prints the words
void scorestage::printScoreText(){
    mvwprintw(scoreWin,0,0,"Stage: ");
    mvwprintw(scoreWin,2,0,"Score: ");
    wrefresh(scoreWin);
}

//prints score and level
void scorestage::printScoreStage(){
    mvwprintw(scoreWin, 0 ,8, "%d", getStage());
    mvwprintw(scoreWin, 2 ,8, "%d ",this->score);
    wrefresh(scoreWin);
}

