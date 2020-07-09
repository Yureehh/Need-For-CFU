#include "obstacle.hpp"


obstacle::obstacle(){
    this->c = " ";
    this->score = 0;
    this->color = 1;
}


obstacle::obstacle(const char *c = " ", int score=0, int color=1){
    this->c = c;
    this->score = score;
    this->color = color;
}

// Getters
const char *obstacle::getChar(){
    return c;
}

int obstacle::getScore(){
    return score;
}

int obstacle::getColor(){
    return color;
}