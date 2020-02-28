#include "level.h"

level::level(){
    this->next = NULL;
    this->prev = NULL;
    this->track = NULL;
    oneXone = obstacle(" ", 0);
}

level::level(int stage, int length, level *prev){    

    oneXone = obstacle("K", -100);
    twoXtwo = obstacle("T", -50);
    boost = obstacle("H", 50);

    this->length = length;
    this->next = NULL;
    this->prev = NULL;

    if(prev){
        this->prev = new level;
        this->prev = prev;
    }

    track = new ptrObstacle*[length];
    for (int i = 0; i < length; i++){
        track[i] = new ptrObstacle[47];
    }

    for (int i = 0; i < length; i++){
        for (int j = 0; j < 47; j++){
            if ( i%12 == 0 && j == 23)
                track[i][j] = {true, &oneXone};
            else
                track[i][j] = {false, NULL};
        }

    }

}

bool level::is_Free(int y, int x){
    return track[y][x].obst == NULL ;
}

const char *level::get_Char(int y, int x){
    return track[y][x].obst->getChar();
}

int level::get_Length(){
    return length;
}