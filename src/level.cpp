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
    oneXone = obstacle("K", -100, 1);
    twoXone = obstacle("T", -1500, 1);
    boost = obstacle("H", 200, 2);

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
   
//-------start here
    int lastspawn=0;
    int maxH=2;
    int maxK=stage*3;
    int maxT=stage;
    int maxSpawnPerLine=2;
    for (int i = 0; i < length-1; i++){
        maxSpawnPerLine=3;
        for (int j = 0; j < 47; j++){
            influence=rand()%20;
            if(i < length - 25 && i > 5){
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
                        lastspawn=3;
                        maxK--;
                        maxSpawnPerLine--;
                    }
                    break;
                case 2:
                    if(lastspawn==0 && maxT!=0 && j<46 && maxSpawnPerLine!=0){
                        track[i][j] = {true, &twoXone};
                        switch (rand()%4)
                        {
                        case 0:
                            track[i+1][j] = {false, NULL};
                            track[i+1][j] = {true, &twoXone};
                            break;
                        case 1:
                            track[i][j+1] = {false, NULL};
                            track[i][j+1] = {true, &twoXone};
                            break;
                        case 2:
                            track[i][j-1] = {false, NULL};
                            track[i][j-1] = {true, &twoXone};
                            break;
                        case 3:
                            track[i-1][j] = {false, NULL};
                            track[i-1][j] = {true, &twoXone};
                            break;
                        default:
                            break;
                        }
                        lastspawn=3;
                        maxT--;
                        maxSpawnPerLine--;
                    }
                    break;
                case 7:
                if(maxH!=0){
                    track[i][j] = {true, &boost};
                    maxH--;}
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
           
            if ( i%12 == 0 && i!=0 && j == 23)
                track[i][j] = {true, &oneXone};
            else
                track[i][j] = {false, NULL};
                
        }
    }

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