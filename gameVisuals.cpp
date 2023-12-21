#include "gameVisuals.h"
#include <string>

	//inline const char* GAME_OVER = "GAME OVER"

gameVisuals::gameVisuals(){
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


	void gameVisuals::procesInput(){
		switch(getch()){
			case 'w':
				Game.flipBlock();
				break;
			case 'a':
				Game.blockGoLeft();
				break;
			case 'd':
				Game.blockGoRight();
				break;
			case 's':
				Game.blockGoDawn();
				break;
		}
	}


	void gameVisuals::printBord(){
		for(int i = 0 ; i < BORD_HEIGHT; ++i){
			for(int j = 0 ; j < BORD_LENGHT ; ++j){
				//werase(win);
				if(Game.getBordUnit(i,j)){
					wattron(win,COLOR_PAIR(BORD_COLOR));
					mvwprintw(win,i,2*j,"  ");
					wattroff(win,COLOR_PAIR(BORD_COLOR));
				}else{
					//continue;

					wattron(win,COLOR_PAIR(BORD_FON_COLOR));
					mvwprintw(win,i,2*j,"  ");
					wattroff(win,COLOR_PAIR(BORD_FON_COLOR ));
					//mvwprintw(win,i,2*j,"  ");
				}
			}	
		}
	}
	

	void gameVisuals::printBlock(){
		int color = Game.getColor();
		for(int i = 0 ; i < Game.getFigurHeight(); ++i){
			for(int j = 0 ; j < Game.getFigurLenght() ; ++j){	
				if(Game.getFigurUnit(i,j)){
					wattron(win,COLOR_PAIR(color));
					mvwprintw(win, Game.getY()+i, 2*(Game.getX()+j),"  ");
					wattroff(win,COLOR_PAIR(color));
				}else{
					continue;
					//mvwprintw(win, Game.getY()+i, 2*(Game.getX()+j),"  ");
				}
			}	
		}
	}

	void gameVisuals::printPoint(){
		size_t sizeMesig = 7;
		std::string pointMesig = "POINT: ";
		std::string getPoint = std::to_string(Game.getPoint());
		mvwprintw(win,BORD_HEIGHT , POINT_PRINT_X , "%s",pointMesig.c_str());
		mvwprintw(win,BORD_HEIGHT ,POINT_PRINT_X + sizeMesig , "%s", getPoint.c_str());
	}

	
	void gameVisuals::startGame(){
		Game.newFigur();
		while(!Game.gameOver()){
			werase(win);
			Game.gameDeleteRow();
			printBord();
			printBlock();
			printPoint();
			procesInput();
			if(Game.blockMoveDelay()){
				Game.blockGoDawn();
			}
			//box(win, 0, 0);
			wrefresh(win);
		}
		//if(Game.gameOver()){
		//	mvwaddch(win,BORD_HEIGHT/2 , BORD_LENGHT/2 , GAME_OVER);
		//}
	}