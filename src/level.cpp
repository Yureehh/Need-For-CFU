#include <iostream>
#include "level.h"

level::level(int stage, int length, level *prev = NULL){

    this->next = NULL;
    this->prev = prev;

    track = new char*[47];
    for (int i = 0; i < 47; i++){
        track[i] = new char[length];
    }

    for (int i = 0; i < length; i++){
        for (int j = 0; j < 47; j++){
            if ( i%12 == 0 && j == 23)
                track[i][j] = 'K';
            else
                track[i][j] = ' ';
        }

    }

}

char level::get_Pos(int x, int y){
    return track[x][y];
}