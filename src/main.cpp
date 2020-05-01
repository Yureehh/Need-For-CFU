#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "game.h"
#include "level.h"
#include "utilities.h"

// ! Usare mvinch(x,y) per sapere che char è fatto vedere in x,y

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

const char *choices[] = {
                        "Start Game",
                        "Quit",
                  };

int main(int argc, char *argv[]){

    int termX, termY;

    ITEM** my_items;
	int c;				
	MENU *my_menu;
	int n_choices, i;
	ITEM *cur_item;

    // _ Setup ncurses
    initscr();

    // Setup Colors
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);

    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, termY, termX);

    // _ Menù
    // ? Set window
    WINDOW *my_menu_win = newwin(termY, termX, 0, 0);

    keypad(my_menu_win, TRUE);

    // ? Print title
    mvwprintw(my_menu_win, termY/4 - 2, termX/2 - 42, "_____   __         _________   __________                 ______________________  __");
    mvwprintw(my_menu_win, termY/4 - 1, termX/2 - 42, "___  | / /_______________  /   ___  ____/_____________    __  ____/__  ____/_  / / /");
    mvwprintw(my_menu_win, termY/4    , termX/2 - 42, "__   |/ /_  _ \\  _ \\  __  /    __  /_   _  __ \\_  ___/    _  /    __  /_   _  / / /");
    mvwprintw(my_menu_win, termY/4 + 1, termX/2 - 42, "_  /|  / /  __/  __/ /_/ /     _  __/   / /_/ /  /        / /___  _  __/   / /_/ /");
    mvwprintw(my_menu_win, termY/4 + 2, termX/2 - 42, "/_/ |_/  \\___/\\___/\\__,_/      /_/      \\____//_/         \\____/  /_/      \\____/");

    // ? Set up menu choices
    n_choices = ARRAY_SIZE(choices);
	my_items = new ITEM*[n_choices + 1];

	for(i = 0; i < n_choices; ++i)
	        my_items[i] = new_item(choices[i],"");
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu(my_items);

    // ? Menu's Windows
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 13, termY/4*3, termX/2 - 6));
    
    set_menu_mark(my_menu, " * ");

    // ? Post-it
	post_menu(my_menu);
	wrefresh(my_menu_win);

    int startgame = false;

	while(!startgame && (c = wgetch(my_menu_win)) != KEY_F(1)){
        switch(c){
            case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
            case 10: // ENTER
                switch(item_index(current_item(my_menu))){
                    case 0:
                        startgame = true;
                        break;
                    case 1:
                        endwin();
                        exit(0);
                        break;
                }
		}
        wrefresh(my_menu_win);
	}
    
    // ? Clear all the menu
    unpost_menu(my_menu);
    free_menu(my_menu);
    for(i = 0; i < n_choices; ++i)
            free_item(my_items[i]);

    erase();

    //inizialize points
    scorestage s = scorestage(901);
    s.printScoreStage();

    //Print the UI
    game g = game();
    g.printUI();
    g.printScore();

  
    //countdown
    mvprintw(21, 24, "3");
    refresh();
    sleep(1);
    mvprintw(21, 24, "2");
    refresh();
    sleep(1);
    mvprintw(21, 24, "1");
    refresh();
    sleep(1);
    mvprintw(21, 24, " ");
    

    //prints the starting Track with the car and obstacles
    g.printTrack();
    //g.primaStampa();
    g.carPrint();
    refresh();

    int timer = 0;
    char ch=' ';


    //the game itself, for now u can only move the car
    while(ch != 113){
        
        usleep(3125);

        if(kbhit()){
            ch = getch();
            if(ch == 'a' || ch == 68){
                g.carClean();
                if(!g.carLeft())
                    s.SubScore(500);
                
            }  

            if(ch == 'd' || ch == 67){
                g.carClean();
                if(!g.carRight())
                    s.SubScore(500);
            }

            s.AddScore(g.collisions());
        
            if(s.getScore() <= 0)
                if( g.loss(s) )
                    break;

        }


        if(timer<=0){
            g.downTrack();
            
            s.AddScore(g.collisions()); // + 25);

            timer = 200; //800
             
        } else
            timer--;

/*
        if(s.getStage() != s.getLastLevel()){
            g.clearLevel();
            erase();
            g.printUI();

            if(s.getStage() > s.getLastLevel()){
                if(s.getScore() == s.getMaxScore() )
                    g.forwardNewLevel(s.getStage());
                else
                    g.forwardLevel();
            }

            else{
                g.backLevel();
            }

            s.setlastLevel();
        }
        else
        
            g.clearLine();
*/        



         //inserire animazione cambio livello w la figa O:


        s.printScoreStage();
        g.carPrint();    
        refresh();
        if( g.loss(s) )
            break;

    }


    endwin();
    return 0;
}
