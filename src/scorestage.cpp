#include "scorestage.h"


//constructor to inizialize points
scorestage::scorestage(int s){
    score = s;
    record = lowest = score;
    lastLevel = getStage();
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

//prints score and level
void scorestage::printScoreStage(){
    mvprintw(20 ,66, "%d", getStage());
    mvprintw(22 ,66, "%d ",this->score);
}

