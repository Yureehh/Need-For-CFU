#include "scorestage.h"


//constructor to inizialize points
scorestage::scorestage(int s=1){
    score = s;
    record = score;
}

//getter for the score
int scorestage::GetScore(){
    return score;
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

//prints score and level
void scorestage::PrintScoreStage(){
    mvprintw(20 ,66, "%d", score/1000);
    mvprintw(22 ,66, "%d ",this->score);
}

