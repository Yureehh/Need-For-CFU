#include <iostream>
#include <menu.h>
#include <cstdlib>
#include <unistd.h>
#include "game.h"

// ! Usare mvinch(x,y) per sapere che char è fatto vedere in x,y

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

const char *choices[] = {
                        "Start Game",
                        "Credits",
                        "Quit",
                  };

bool mainMenu(){

    flushinp(); // Discard any keyboard input

    int termX, termY;
    getmaxyx(stdscr, termY, termX);

	int c;
	int n_choices, i;
    MENU *menu;
    ITEM** items;
	ITEM *currentIitem;

    // _ Title
    attron(COLOR_PAIR(4));
    mvprintw(termY/4 - 2, termX/2 - 42, "_____   __         _________   __________                 ______________________  __");
    mvprintw(termY/4 - 1, termX/2 - 42, "___  | / /_______________  /   ___  ____/_____________    __  ____/__  ____/_  / / /");
    mvprintw(termY/4    , termX/2 - 42, "__   |/ /_  _ \\  _ \\  __  /    __  /_   _  __ \\_  ___/    _  /    __  /_   _  / / /");
    mvprintw(termY/4 + 1, termX/2 - 42, "_  /|  / /  __/  __/ /_/ /     _  __/   / /_/ /  /        / /___  _  __/   / /_/ /");
    mvprintw(termY/4 + 2, termX/2 - 42, "/_/ |_/  \\___/\\___/\\__,_/      /_/      \\____//_/         \\____/  /_/      \\____/");
    attroff(COLOR_PAIR(4));

    // ? Color
    attron(COLOR_PAIR(3));

    // First line
    mvprintw(termY/4 - 2, termX/2 - 42, "___");
    mvprintw(termY/4 - 2, termX/2 - 42 + 19, "_______");
    mvprintw(termY/4 - 2, termX/2 - 42 + 31, "____");
    mvprintw(termY/4 - 2, termX/2 - 42 + 58, "___");
    mvprintw(termY/4 - 2, termX/2 - 42 + 67, "___");
    mvprintw(termY/4 - 2, termX/2 - 42 + 76, "__");

    // Second Line
    mvprintw(termY/4 - 1, termX/2 - 42, "___");
    mvprintw(termY/4 - 1, termX/2 - 42 + 10, "__");
    mvprintw(termY/4 - 1, termX/2 - 42 + 14, "___");
    mvprintw(termY/4 - 1, termX/2 - 42 + 19, "___");
    mvprintw(termY/4 - 1, termX/2 - 42 + 31, "___");
    mvprintw(termY/4 - 1, termX/2 - 42 + 41, "__");
    mvprintw(termY/4 - 1, termX/2 - 42 + 45,"____");
    mvprintw(termY/4 - 1, termX/2 - 42 + 58, "__");
    mvprintw(termY/4 - 1, termX/2 - 42 + 67, "__");
    mvprintw(termY/4 - 1, termX/2 - 42 + 76, "_");

    // Third Line
    mvprintw(termY/4, termX/2 - 42, "__");
    mvprintw(termY/4, termX/2 - 42 + 9, "_");
    mvprintw(termY/4, termX/2 - 42 + 31, "__");
    mvprintw(termY/4, termX/2 - 42 + 40, "_");
    mvprintw(termY/4, termX/2 - 42 + 58, "_");
    mvprintw(termY/4, termX/2 - 42 + 66, "__");
    mvprintw(termY/4, termX/2 - 42 + 75, "_");


    // Fourth Line
    mvprintw(termY/4 + 1, termX/2 - 42, "");
    mvprintw(termY/4 + 1, termX/2 - 42, "_");
    mvprintw(termY/4 + 1, termX/2 - 42 + 31, "_");
    mvprintw(termY/4 + 1, termX/2 - 42 + 66, "_");

    attroff(COLOR_PAIR(3));

    box(stdscr, '|', '-');
    refresh();

    // _ Menù
    // ? Set windows
    WINDOW *menuWin = newwin(8, 16, termY/4*3, termX/2 - 6);
    WINDOW *creditsWin = newwin(5, 20,termY/4*3, termX/2 - 9);

    keypad(menuWin, TRUE);

    // ? Set up menu choices
    n_choices = ARRAY_SIZE(choices);
	items = new ITEM*[n_choices + 1];

	for(i = 0; i < n_choices; ++i)
	        items[i] = new_item(choices[i],"");
	items[n_choices] = (ITEM *)NULL;

	menu = new_menu(items);

    // ? Menu's Windows
    set_menu_win(menu, menuWin);
    set_menu_sub(menu, derwin(menuWin, 6, 13, 1, 1));
    
    set_menu_mark(menu, " > ");
    set_menu_spacing(menu, 0, 2, 0);

    // ? Post-it
	post_menu(menu);
	wrefresh(menuWin);

    int startgame = false;

	while(!startgame && (c = tolower(wgetch(menuWin))) != KEY_F(1)){
        switch(c){
            case 's':
		        menu_driver(menu, REQ_DOWN_ITEM);
				break;
			case 'w':
				menu_driver(menu, REQ_UP_ITEM);
				break;
            case 10: // ENTER
                switch(item_index(current_item(menu))){
                    case 0:
                        startgame = true;
                        break;
                    case 1:                      
                        unpost_menu(menu);
                        wclear(menuWin);
                        wrefresh(menuWin);

                        mvwprintw(creditsWin, 0, 0, "Alessandro Filippini");
                        mvwprintw(creditsWin, 2, 0, "   Filippo Bertozzi");
                        mvwprintw(creditsWin, 4, 0, "      Juri Fabbri");
                        wrefresh(creditsWin);
                        refresh();

                        sleep(1);
                        flushinp();
                        while(!kbhit());

                        // Restamp the menu
                        wclear(creditsWin);
                        wrefresh(creditsWin);
                        post_menu(menu);
                        wrefresh(menuWin);
                        refresh();

                        flushinp();
                        break;
                    case 2:
                        return false; // Aka quit
                        break;
                }
		}
        wrefresh(menuWin);
	}
    
    // ? Clear all the menu
    unpost_menu(menu);
    free_menu(menu);
    for(i = 0; i < n_choices; ++i)
            free_item(items[i]);
            
    erase();

    return true;

}

void startGame(){
    
    //inizialize points and game
    scorestage s = scorestage(300);
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

    flushinp(); // Discard any keyboard input

    //prints the starting Track with the car and obstacles
    g.printTrack();
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
                    g.printTrack();
                    break;
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

            timer = g.clock(); //!960 fa 3 secondi di pausa  

             
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

    erase();

}

int main(int argc, char *argv[]){

    // _ Setup ncurses
    setlocale( LC_ALL, "" );
    initscr();

    // Setup Colors
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);

    init_pair(3, COLOR_MAGENTA, -1);
    init_pair(4, COLOR_CYAN, -1);

    noecho();
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Start the game, quit only if when specified
    while(mainMenu())
        startGame();  

    endwin();

}
