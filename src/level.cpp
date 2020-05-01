#include "level.h"

level::level(){
    this->next = NULL;
    this->prev = NULL;
    this->track = NULL;
    oneXone = obstacle(" ", 0, 1);
}

level::level(int stage, int length, level *l, bool b){ 
    srand((stage+time(0))/2);   
    int influence;
    oneXone = obstacle("K", -(500+(stage*30)), 1);
    boost = obstacle("H", (150+(stage*10)), 2);

    this->length = length;
    this->next = NULL;
    this->prev = NULL;

    if(b){
        if(l!=NULL){
        this->prev = new level;
        this->prev = l;
        }   
    } else {
        if(l!=NULL){
        this->next = new level;
        this->next = l;
        }
    }


    track = new ptrObstacle*[length];
    for (int i = 0; i < length; i++){
        track[i] = new ptrObstacle[47];
    }
/*

    // Test Pilota
    track[length/2][20] = {true, &oneXone};
    track[length/2][26] = {true, &oneXone};

    // Test Route
    track[length/2 - 1][18] = {true, &oneXone};
    track[length/2 - 1][28] = {true, &oneXone};
    track[length/2 + 1][16] = {true, &oneXone};
    track[length/2 + 1][30] = {true, &oneXone};
    track[0][10 * stage] = {true, &oneXone};
    track[39][15*stage] = {true, &oneXone};
*/
   
    int lastspawn=0;
    int maxH=3+(stage/2);
    int maxHPerLine=1;
    int maxK=40+(stage*10);
    int maxSpawnPerLine=3;
    for (int i = 0; i < length-1; i++){
        maxSpawnPerLine=1+(stage/3);
        maxHPerLine=1;
        for (int j = 0; j < 47; j++){
            influence=rand()%20;
            if(true){       //f(i < length - (length/2) && i > 5)
                switch (influence)
                {
                case 0:
                    track[i][j] = {false, NULL};
                    if(lastspawn>0)
                        lastspawn--;
                    break;
                case 1:
                    if(lastspawn==0 && maxK!=0 && maxSpawnPerLine!=0){
                        track[i][j] = {true, &oneXone};
                        if(i<=length-1 && i> length-10)
                            setVisible(i,j,false);
                        lastspawn=3;
                        maxK--;
                        maxSpawnPerLine--;
                    }
                    break;
                
                case 7:
                if(maxH!=0 && maxHPerLine!=0){
                    track[i][j] = {true, &boost};
                    if(i<=length-1 && i> length-10)
                            setVisible(i,j,false);
                    maxH--;
                    maxHPerLine--;
                    }
                     if(lastspawn>0)
                        lastspawn--;
                    break;
                default:
                    track[i][j] = {false, NULL};
                     if(lastspawn>0)
                        lastspawn--;
                    break;
                }
            }
           
                
        }
    }/*
    for (int i = 0; i < length-1; i++){
        for (int j = 0; j < 47; j++){
            if(i<=length-1 && i> length-10)
            setVisible(i,j,false);
        }
    }
*/
//---------
}

bool level::isFree(int y, int x){
    return track[y][x].obst == NULL ;
}

void level::setVisible(int y, int x, bool b){
     track[y][x].visible = b ;
}

bool level::isVisible(int y, int x){
    return track[y][x].visible ;
}

const char *level::getChar(int y, int x){
    return track[y][x].obst->getChar();
}

int level::getScore(int y, int x){
    return track[y][x].obst->getScore();
}

int level::getColor(int y, int x){
    return track[y][x].obst->getColor();
}

int level::getLength(){
    return length;
}