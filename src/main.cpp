#include <iostream>
#include <cstdlib>
#include <menu.h>
#include "game.hpp"

bool mainMenu(){

    flushinp(); // Discard any keyboard input

    int termX, termY;
    getmaxyx(stdscr, termY, termX);

    // _ Title
    attron(COLOR_PAIR(4));
    mvprintw(termY/4 - 2, termX/2 - 25, "   _____          _   __    _           __      ______");
    mvprintw(termY/4 - 1, termX/2 - 25, "  __  _/  ____   (_)_/ /   (_) ____ _  / /     / ____/");
    mvprintw(termY/4    , termX/2 - 25, "   / /   / __ \\ / /_  __/ / / / __ `/ / /     / /     ");
    mvprintw(termY/4 + 1, termX/2 - 25, "  / /   / / / // / / /   / / / /_/ /_/ /     / /___   ");
    mvprintw(termY/4 + 2, termX/2 - 25, "/___/  /_/ /_//_/  \\__/ /_/  \\__,_/ /_/      \\____/   ");
    attroff(COLOR_PAIR(4));

    // ? Color
    attron(COLOR_PAIR(3));

    // First line
    mvprintw(termY/4 - 2, termX/2 - 25, "___");
    mvprintw(termY/4 - 2, termX/2 - 25 + 14, "____");
    mvprintw(termY/4 - 2, termX/2 - 25 + 19, "___");
    mvprintw(termY/4 - 2, termX/2 - 25 + 24, "____");
    mvprintw(termY/4 - 2, termX/2 - 25 + 36, "____");
    mvprintw(termY/4 - 2, termX/2 - 25 + 45, "___");

    // Second Line
    mvprintw(termY/4 - 1, termX/2 - 25, "__");
    mvprintw(termY/4 - 1, termX/2 - 25 + 8, "__");
    mvprintw(termY/4 - 1, termX/2 - 25 + 14, "___");
    mvprintw(termY/4 - 1, termX/2 - 25 + 24, "___");
    mvprintw(termY/4 - 1, termX/2 - 25 + 30, "_");
    mvprintw(termY/4 - 1, termX/2 - 25 + 37, "__");
    mvprintw(termY/4 - 1, termX/2 - 25 + 45, "__");


    // Third Line
    mvprintw(termY/4, termX/2 - 25, "___");
    mvprintw(termY/4, termX/2 - 25 + 7, "__");
    mvprintw(termY/4, termX/2 - 25 + 15, "_");
    mvprintw(termY/4, termX/2 - 25 + 25, "_");
    mvprintw(termY/4, termX/2 - 25 + 29, "_");
    mvprintw(termY/4, termX/2 - 25 + 37, "_");
    mvprintw(termY/4, termX/2 - 25 + 45, "_");


    // Fourth Line
    mvprintw(termY/4 + 1, termX/2 - 25, "__");
    mvprintw(termY/4 + 1, termX/2 - 25 + 7, "_");
    mvprintw(termY/4 + 1, termX/2 - 25 + 22, "_");
    mvprintw(termY/4 + 1, termX/2 - 25 + 24, "_");
    mvprintw(termY/4 + 1, termX/2 - 25 + 36, "_");

    attroff(COLOR_PAIR(3));

    mvprintw(termY/4 + 6, termX/2 - 13,"\"See You At The Finish Line\"");

    box(stdscr, '|', '-');
    refresh();

    // _ Menù
    // ? Set windows
    WINDOW *menuWin = newwin(8, 16, termY/4*3, termX/2 - 7);
    WINDOW *creditsWin = newwin(5, 20, termY/4*3 + 1, termX/2 - 10);

    keypad(menuWin, TRUE);
    
    const char *choices[] = {
                        "Start Game",
                        "Credits",
                        "Quit",
                  };

    // ? Set up menu choices
    int n_choices = sizeof(choices) / sizeof(choices[0]);
	ITEM** items = new ITEM*[n_choices + 1];

	for(int i = 0; i < n_choices; ++i)
	        items[i] = new_item(choices[i],"");
	items[n_choices] = (ITEM *)NULL;

	MENU *menu = new_menu(items);

    // ? Menu's Windows
    set_menu_win(menu, menuWin);
    set_menu_sub(menu, derwin(menuWin, 6, 13, 1, 1));
    
    set_menu_mark(menu, " > ");
    set_menu_spacing(menu, 0, 2, 0);

    // ? Post-it
	post_menu(menu);
	wrefresh(menuWin);

    int startgame = false;
    int c;

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
    for(int i = 0; i < n_choices; ++i)
            free_item(items[i]);
            
    erase();

    return true;

}


void startGame(){
    
    //inizialize points and game
    scorestage s = scorestage(0);
    game g = game( s.getStage() );
    
    //Print the UI
    g.printUI();
    s.printScoreText();
    s.printScoreStage();


    //Countdown
    mvprintw(21, 22, "Ready");
    refresh();
    sleep(1);
    mvprintw(21, 22, " Set ");
    refresh();
    sleep(1);
    mvprintw(21, 22, " Go! ");
    refresh();
    sleep(1);

    flushinp(); // Discard any keyboard input

    //Prints the starting Track with the car and obstacles
    g.printTrack();
    g.carPrint();
    refresh();


    int timer = 0;
    char ch=' ';


    //the cicle is the game itself
    while(ch != 113){
        
        //number of milliseconds the game gets paused every cicle
        usleep(3125); 

        //checks if lateral displacements collides with walls or obstacles
        if(kbhit()){
            ch = tolower(getch()); // Avoids mis match with 'A' and 'a'

            //check if player wants to move laterally, if u collide points are subtracted/added.
            switch(ch){
                
                case 'a':
                    g.carClean();
                    if(!g.carLeft())
                        s.addScore(-1000);
                    break;
            
                case 'd':
                    g.carClean();
                    if(!g.carRight())
                        s.addScore(-1000);
                    break;
                //if the input is "q" the game gets paused
                case 27:
                    g.pause();
                    g.printTrack();
                    break;
            }

            s.addScore( g.collisions() );
            //check if the player has lost
            if(s.getScore() <= 0)
                if( g.loss(s) )
                    break;
        }

        //if the right amount of seconds has passed the obstacles are lowered by 1 line and collisions are checked
        if(timer<=0){
            g.downTrack();
            
            s.addScore(g.collisions() + 20 ); // + 25);

            timer = g.clock(s.getMaxScore()/1000);

             
        } else
            timer--;    //combination of timer and usleep creates the clock of the map's sliding

        //checks if u have enough points to swap level
        if(s.getStage() != s.getLastLevel()){
            //level gets resetted for the future
            g.clearLevel();
            g.carPrint();
            //check if u have to move to next or previous level
            if(s.getStage() > s.getLastLevel()){
                if(s.getScore() == s.getMaxScore() )
                    g.newLevel(s.getStage(), true );
                else
                    g.forwardLevel();
            }

            else{
                if(s.getScore() == s.getLowestScore() ){
                    g.newLevel(s.getStage(), false );
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
