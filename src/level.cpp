#include "level.h"

level::level(){
    this->next = NULL;
    this->prev = NULL;
    this->track = NULL;
    oneXone = obstacle(" ", 0, 1);
}

level::level(int stage, int length, level *l, bool b){ 
    srand((stage+time(0))/2);   //generiamo il seed che influenzerà il nostro numero casuale
    
    int influence;
    if(stage>8)             //vengono inizializzati gli ostacoli impostando il loro danno
        oneXone = obstacle("K", -(200+(8*100)), 1);
    else
        oneXone = obstacle("K", -(200+(stage*100)), 1);
    
    boost = obstacle("H", 200, 2); //inizializziamo i boost

    this->stage = stage;
    this->length = length;
    this->next = NULL;
    this->prev = NULL;

    if(b){      //assegnamo eventuali livelli precedenti/successivi
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

    track = new ptrObstacle*[length];   //creiamio gli slot per le entità
    for (int i = 0; i < length; i++){
        track[i] = new ptrObstacle[47];
    }

    int lastspawn=0;    //assegnamo le variabili che bilanciano lo spawn delle entità
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
            switch (influence) //lo switch tramite il numero generato casualmente ha 4 possibili casi
            {
            case 0: //in questo caso lo spazio rimane vuoto
                track[i][j] = {false, NULL};
                if(lastspawn>0)
                    lastspawn--;
                break;
            case 1: // in questo caso viene creato un ostacolo
                if(lastspawn==0 && maxK!=0 && maxSpawnPerLine!=0){
                    track[i][j] = {true, &oneXone};
                    if(i<=length-1 && i> length-10)
                        setVisible(i,j,false);
                    lastspawn=3;
                    maxK--;
                    maxSpawnPerLine--;
                }
                break;
                
            case 7: // in questo caso viene creato un boost
            if(maxH!=0 && hDistancing==0){
                if(j>22 && posH){   //questo if in particolare bilancia lo spawn dei boost per tutta la larghezza della mappa
                    track[i][j] = {true, &boost};
                    if(i<=length-1 && i> length-10)
                            setVisible(i,j,false);
                    maxH--;
                    posH=false;
                    hDistancing=5;
                    if(lastspawn>0)
                        lastspawn--;
                    }
                if(j<22 && !posH){  //questo if in particolare bilancia lo spawn dei boost per tutta la larghezza della mappa
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
            default:    // il caso default lascia la cella vuota
                track[i][j] = {false, NULL};
                    if(lastspawn>0)
                    lastspawn--;
                break;
            }
            
        }
    }
}


bool level::isFree(int y, int x){   //restituisce true se lo slot in posizione (x,y) è vuoto
    return track[y][x].obst == NULL ;
}

void level::setVisible(int y, int x, bool b){   //cambia la visibilità di uno slot 
     track[y][x].visible = b ;
}

bool level::isVisible(int y, int x){    //restituisce true o false se uno slot è visibile o no
    return track[y][x].visible ;
}


// getter e setter
int level::getStage(){  
    return stage;
}

int level::getLength(){
    return length;
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