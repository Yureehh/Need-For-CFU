#include <iostream>
#include <ncurses.h>
using namespace std;

// # User Interface geometry (UI)
const char larghezza = 80;
const char altezza = 42;

const char larghezza_layout = 33;
const char altezza_layout = 40;

#ifndef LAYOUT_H
#define LAYOUT_H

class layout {

    protected:
        char UI[altezza][larghezza];
        char mappa[altezza_layout][larghezza_layout];

    public:
        layout();
        void stampa_UI();

};

#endif