#include <iostream>
using namespace std;

const char larghezza = 40;
const char altezza = 30;

class mappa{

protected:
    char layout[larghezza][altezza];

public:

    mappa(){
        for(int i=0; i< altezza;i++) {
            for (int j = 0; j < larghezza; j++) {
                    if(i==0 || i== altezza -1) {
                    layout[i][j] = '-';
                }
                    else{
                        if(j==0 || j == larghezza -1)
                            layout[i][j] = '|';
                        else if(j==1 || j==27)
                            layout[i][j] = '#';
                        else
                            layout[i][j] =' ';
                    }
                }
            }
        }


    void stampa(){
        for(int i=0; i< altezza;i++) {
            for (int j = 0; j < larghezza; j++) {
                cout<<layout[i][j];
            }
                  }
            }


};


int main(){
    mappa pista = mappa();
    pista.stampa();
}