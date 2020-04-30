#include "scorestage.h"


//constructor to inizialize points
scorestage::scorestage(int s=1){
    score = s;
    record = score;
    lastLevel = 1;
}

//getter for the score
int scorestage::getScore(){
    return score;
}

int scorestage::getMaxScore(){
    return record;
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
void scorestage::AddScore(int x){
    score = score + x;
    if(score > record)
        record = score;
}

//sub points
void scorestage::SubScore(int x){
    score = score - x;
}

//prints score and level
void scorestage::printScoreStage(){
    mvprintw(20 ,66, "%d", getStage());
    mvprintw(22 ,66, "%d ",this->score);
}

//check the change of level
int scorestage::LevelChange(){
    if( getStage() == lastLevel)
        return 0;
    else {
        if( getStage() > lastLevel )
            return 1;
        else
            return -1;
        lastLevel = getStage();
    }
    
}

