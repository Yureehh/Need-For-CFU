#include "scorestage.h"


//constructor to inizialize points
scorestage::scorestage(int s=1){
    score = s;
    record = score;
    livelloprec = 1;
}

//getter for the score
int scorestage::GetScore(){
    return score;
}

int scorestage::Getlevelprec(){
    return livelloprec;
}

//getter for the stage
int scorestage::GetStage(){
    return score/1000 + 1;
}

int scorestage::GetMaxScore(){
    return record;
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

void scorestage::setLevelPrec(){
    livelloprec = GetStage();
};

//prints score and level
void scorestage::PrintScoreStage(){
    mvprintw(20 ,66, "%d", GetStage());
    mvprintw(22 ,66, "%d ",this->score);
}

//check the change of level
int scorestage::LevelChange(){
    if( GetStage() == livelloprec)
        return 0;
    else {
        if( GetStage() > livelloprec )
            return 1;
        else
            return -1;
        livelloprec = GetStage();
    }
    
}

