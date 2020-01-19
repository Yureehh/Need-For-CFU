#include "scorestage.h"


//constructor to inizialize points
scorestage::scorestage(int s=1){
        score = s;
    }

//getter for the score
int scorestage::GetScore(){
        return this->score;
    }

//add points
int scorestage::AddScore(int x){
        score = score + x;
    }

//sub points
int scorestage::SubScore(int x){
        score = score - x;
    }

//prints score and level
void scorestage::PrintScoreStage(){
        mvprintw(20 ,66, "%d", score/1000);
        mvprintw(22 ,66, "%d ",this->score);
        
    }

