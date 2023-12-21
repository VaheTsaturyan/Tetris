#ifndef MENU
#define MENU

#include <ncurses.h>

#include "gameVisuals.h"
namespace{
	inline const int MENU_LENGHT = 12;
	inline const int MENU_HEIGHT = 6;
	inline const int START_YM = 2;
	inline const int OPTION_Y = 3;
	inline const int RECORDS_Y = 4;
	inline const int MENU_X = 2;
	inline const int KURSOE_X = 9;
	inline const int KURSOR_START_Y = 2;
}

class Menu{
public:
	Menu();
	void startProces();
	~Menu();
private:
	void start();
	void option();
	void records();
	void input();
	void prinChemps(std::vector<int>& chemps);
	
private:
	WINDOW *menuWin;
	int kursY;
	gameVisuals game;
	bool winIsOpen;
};





#endif // MENU