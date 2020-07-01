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
    if(stage>8)
        oneXone = obstacle("K", -(200+(8*100)), 1);
    else
        oneXone = obstacle("K", -(200+(stage*100)), 1);
    
    boost = obstacle("H", 200, 2);

    this->stage = stage;
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

    int lastspawn=0;
    int maxK=40+(stage*20);
    int maxSpawnPerLine=3;
    int maxH=0;
    bool posH=true;
    if(stage<9)
        maxH=3+(length / (stage*2));
    else
        maxH=12;
    int hDistancing=5;
    for (int i = 0; i < length-1; i++){
        maxSpawnPerLine=1+(stage/3);
        if(hDistancing>0)
            hDistancing--;
        for (int j = 0; j < 47; j++){
            influence=rand()%20;      
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
            if(maxH!=0 && hDistancing==0){
                if(j>22 && posH){
                    track[i][j] = {true, &boost};
                    if(i<=length-1 && i> length-10)
                            setVisible(i,j,false);
                    maxH--;
                    posH=false;
                    hDistancing=5;
                    if(lastspawn>0)
                        lastspawn--;
                    }
                if(j<22 && !posH){
                    track[i][j] = {true, &boost};
                    if(i<=length-1 && i> length-10)
                            setVisible(i,j,false);
                    maxH--;
                    posH=true;
                    hDistancing=5;
                    if(lastspawn>0)
                        lastspawn--;
                    }
                }
                break;
            default:
                track[i][j] = {false, NULL};
                    if(lastspawn>0)
                    lastspawn--;
                break;
            }
            
        }
    }
}

int level::getStage(){
    return stage;
}

int level::getLength(){
    return length;
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

level *level::getPrev(){
    return prev;
}

level *level::getNext(){
    return next;
}

void level::setPrev(level *prev){
    this->prev = prev;
}

void level::setNext(level *next){
    this->next = next;
}