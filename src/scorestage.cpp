#include "scorestage.hpp"

scorestage::scorestage(int s){
    score = s;
    record = lowest = score;
    lastLevel = getStage();
    scoreWin = newwin(3, 20, 20, 58);
    refresh();
}

// Add x point to the Score
void scorestage::addScore(int x){
    score = score + x;
    if(score > record)
        record = score;
    if(score < lowest)
        lowest = score;
}

// Prints Text
void scorestage::printScoreText(){
    mvwprintw(scoreWin,0,0,"Stage: ");
    mvwprintw(scoreWin,2,0,"Score: ");
    wrefresh(scoreWin);
}

// Prints score and level
void scorestage::printScoreStage(){
    mvwprintw(scoreWin, 0 ,8, "%d", getStage());
    mvwprintw(scoreWin, 2 ,8, "%d ",this->score);
    wrefresh(scoreWin);
}


// Getters
int scorestage::getLastLevel(){
    return lastLevel;
}

int scorestage::getLowestScore(){
    return lowest;
}

int scorestage::getMaxScore(){
    return record;
}

int scorestage::getScore(){
    return score;
}

int scorestage::getStage(){
    return score/1000 + 1;
}

// Setters
void scorestage::setlastLevel(){
    lastLevel = getStage();
}
