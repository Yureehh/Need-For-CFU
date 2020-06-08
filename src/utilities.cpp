#include "utilities.h"

bool kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return true;
    } else 
        return false;
    
}


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

    mvprintw(termY/4 + 6, termX/2 - 13,"\"See You At The Finish Line\"");

    box(stdscr, '|', '-');
    refresh();

    // _ Menù
    // ? Set windows
    WINDOW *menuWin = newwin(8, 16, termY/4*3, termX/2 - 6);
    WINDOW *creditsWin = newwin(5, 20, termY/4*3 + 1, termX/2 - 9);

    keypad(menuWin, TRUE);

    
    const char *choices[] = {
                        "Start Game",
                        "Credits",
                        "Quit",
                  };

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