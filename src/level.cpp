#include "level.h"

level::level(){
    this->next = NULL;
    this->prev = NULL;
    this->track = NULL;
    oneXone = obstacle(" ", 0);
}

level::level(int stage, int length, level *prev){ 
    srand((stage+time(0))/2);   
    int influence;
    oneXone = obstacle("K", -1000);
    twoXone = obstacle("T", -1500);
    boost = obstacle("H", 200);

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
//-------start here
    int lastspawn=0;
    int maxH=2;
    int maxK=stage*3;
    int maxT=stage;
    int maxSpawnPerLine=2;
    for (int i = 0; i < length; i++){
        maxSpawnPerLine=3;
        for (int j = 0; j < 47; j++){
            influence=rand()%20;
            if(i>25){
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
            /*
            if ( i%12 == 0 && i!=0 && j == 23)
                track[i][j] = {true, &oneXone};
            else
                track[i][j] = {false, NULL};
                */
        }
    }

//---------
    
}

bool level::isVisible(int y, int x){
    return track[y][x].visible ;
}

void level::hasHit(int y, int x){
     track[y][x].visible = false ;
}

bool level::is_Free(int y, int x){
    return track[y][x].obst == NULL ;
}

const char *level::get_Char(int y, int x){
    return track[y][x].obst->getChar();
}

int level::get_Score(int y, int x){
    return track[y][x].obst->getScore();
}

int level::get_Length(){
    return length;
}

void level::setNext(int s, int h, level *l){
    this -> next = new level(s, h, l );
}