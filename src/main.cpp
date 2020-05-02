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
    setlocale( LC_ALL, "" );
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

    // _ Title
    mvprintw(termY/4 - 2, termX/2 - 42, "_____   __         _________   __________                 ______________________  __");
    mvprintw(termY/4 - 1, termX/2 - 42, "___  | / /_______________  /   ___  ____/_____________    __  ____/__  ____/_  / / /");
    mvprintw(termY/4    , termX/2 - 42, "__   |/ /_  _ \\  _ \\  __  /    __  /_   _  __ \\_  ___/    _  /    __  /_   _  / / /");
    mvprintw(termY/4 + 1, termX/2 - 42, "_  /|  / /  __/  __/ /_/ /     _  __/   / /_/ /  /        / /___  _  __/   / /_/ /");
    mvprintw(termY/4 + 2, termX/2 - 42, "/_/ |_/  \\___/\\___/\\__,_/      /_/      \\____//_/         \\____/  /_/      \\____/");

    box(stdscr, '|', '-');
    refresh();

    // _ Menù
    // ? Set window
    WINDOW *my_menu_win = newwin(8, 16, termY/4*3, termX/2 - 6);
    box(my_menu_win, 0, 0);

    keypad(my_menu_win, TRUE);

    // ? Set up menu choices
    n_choices = ARRAY_SIZE(choices);
	my_items = new ITEM*[n_choices + 1];

	for(i = 0; i < n_choices; ++i)
	        my_items[i] = new_item(choices[i],"");
	my_items[n_choices] = (ITEM *)NULL;

	my_menu = new_menu(my_items);

    // ? Menu's Windows
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 13, 1, 1));
    
    set_menu_mark(my_menu, " > ");

    // ? Post-it
	post_menu(my_menu);
	wrefresh(my_menu_win);

    int startgame = false;

	while(!startgame && (c = tolower(wgetch(my_menu_win))) != KEY_F(1)){
        switch(c){
            case 's':
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case 'w':
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

    //inizialize points and game
    scorestage s = scorestage(1950);
    game g = game( s.getStage() );

    //Print the UI
    g.printUI();
    s.printScoreText();
    s.printScoreStage();


    //countdown
    mvprintw(21, 22, "Ready");
    refresh();
    sleep(1);
    mvprintw(21, 22, " Set ");
    refresh();
    sleep(1);
    mvprintw(21, 22, " Go! ");
    refresh();
    sleep(1);
    //mvprintw(21, 24, " ");
    

    //prints the starting Track with the car and obstacles
    g.printTrack();
    //g.primaStampa();
    g.carPrint();
    refresh();

    int timer = 0;
    char ch=' ';


    //the game itself, for now u can only move the car
    while(ch != 113){
        
        //number of milliseconds the game gets paused every cicle
        usleep(3125);

        //checks if lateral displacements collides with walls or obstacles
        if(kbhit()){
            ch = tolower(getch()); // Avoids mis match with 'A' and 'a'

            switch(ch){
            
                case 'a':
                    g.carClean();
                    if(!g.carLeft())
                        s.addScore(-500);
                    break;
            
                case 'd':
                    g.carClean();
                    if(!g.carRight())
                        s.addScore(-500);
                    break;
                
                case 27:
                    g.pause();
            }

            s.addScore( g.collisions() );

            if(s.getScore() <= 0)
                if( g.loss(s) )
                    break;
        }

        //if the right amount of seconds has passed the obstacles are lowered by 1 line and collisions are checked
        if(timer<=0){
            g.downTrack();
            
            s.addScore(g.collisions() + 10 ); // + 25);

            timer = 200; //!960 fa 3 secondi di pausa  

             
        } else
            timer--;    //combination of timer and usleep creates the clock of the map's sliding

        //checks if u have enough points to swap level
        if(s.getStage() != s.getLastLevel()){
            
            g.clearLevel();
            g.carPrint();
            
            if(s.getStage() > s.getLastLevel()){
                if(s.getScore() == s.getMaxScore() )
                    g.NewLevel(s.getStage(), true );
                else
                    g.forwardLevel();
            }

            else{
                if(s.getScore() == s.getLowestScore() ){
                    g.NewLevel(s.getStage(), false );
                }

                else
                    g.backLevel();
            }
            // Reprint everything inside the trackWindow
            g.printUI();
            g.printTrack();
            s.printScoreText();

            s.setlastLevel();
        }
        else
            g.clearLine();

        s.printScoreStage();
        g.carPrint();
        refresh();
        if( g.loss(s) )
            break;

    }


    endwin();
}
