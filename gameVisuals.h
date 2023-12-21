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
	gameVisuals();
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