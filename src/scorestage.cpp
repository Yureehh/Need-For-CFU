#include "scorestage.h"

scorestage::scorestage(int s=1){
        score = s;
    }

int scorestage::GetScore(){
        return this->score;
    }

int scorestage::AddScore(int x){
        score = score + x;
    }

int scorestage::SubScore(int x){
        score = score - x;
    }

void scorestage::PrintScoreStage(){
        mvprintw(20 ,66, "%d", score/1000);
        mvprintw(22 ,66, "%d ",this->score);
        
    }

