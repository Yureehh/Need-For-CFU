#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <menu.h>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

bool kbhit();

bool mainMenu();
