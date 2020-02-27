#include "obstacle.h"

obstacle::obstacle(){
    this->c = " ";
    this->score = 0;
}

obstacle::obstacle(const char *c = " ", int score=0){
    this->c = c;
    this->score = score;
}

const char *obstacle::getChar(){
    return c;
}

int obstacle::getScore(){
    return score;
}