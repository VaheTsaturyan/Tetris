#ifndef GAME_VISUALS
#define GAME_VISUALS

#include <ncurses.h>

#include "gameLogic.h"


namespace {
	inline const size BORD_WIN_HEIGHT = BORD_HEIGHT+1;
	inline const size BORD_WIN_LENGHT = 2*BORD_LENGHT;
	inline const size BORD_COLOR = 3;
	inline const size BORD_FON_COLOR = 7;
	inline const size POINT_PRINT_X = 2;
	
}


class gameVisuals{
public:
	gameVisuals(){
		initscr();
    	cbreak();
    	noecho();
    	curs_set(0);
    	keypad(stdscr, TRUE);
    	nodelay(stdscr, TRUE);
		start_color();
		init_pair(1,COLOR_BLACK,COLOR_YELLOW );
		init_pair(2,COLOR_BLACK,COLOR_MAGENTA );
		init_pair(3,COLOR_BLACK,COLOR_RED );
		init_pair(4,COLOR_BLACK,COLOR_GREEN );
		init_pair(5,COLOR_BLACK,COLOR_BLUE );
		init_pair(6,COLOR_BLACK,COLOR_CYAN );
		init_pair(7,COLOR_BLACK,COLOR_WHITE);
		//raw();
		win = newwin( BORD_WIN_HEIGHT,BORD_WIN_LENGHT,0,0);

	}



	void startGame();
	void procesInput();
	void printBord();
	void printBlock();
	void printPoint();

	~gameVisuals(){
		endwin();
	}
public:
	WINDOW *win;
private:
	game Game;
};

#endif