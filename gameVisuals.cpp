#include "gameVisuals.h"

	//inline const char* GAME_OVER = "GAME OVER"


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
		std::string point = "POINT: "
		mvwprintw(win,BORD_HEIGHT , POINT_PRINT_X ,point);
		mvwaddch(win,BORD_HEIGHT , POINT_PRINT_X + sizeof(point), Game.getPoint());
	}0

	void gameVisuals::printPoint(){
		mvwaddch(win,BORD_WIN_HEIGHT , BORD_LENGHT/2 , Game.getPoint());
	}

	
	void gameVisuals::startGame(){
		Game.newFigur();
		while(!Game.gameOver()){
			werase(win);
			Game.gameDeleteRow();
			printBord();
			printBlock();
			//printPoint();
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