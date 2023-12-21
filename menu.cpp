#include "menu.h"

	Menu::Menu():kursY(KURSOR_START_Y),winIsOpen(true){
		initscr();
    	cbreak();
    	noecho();
    	curs_set(0);
    	keypad(stdscr, TRUE);
    	nodelay(stdscr, TRUE);
		menuWin = newwin(MENU_HEIGHT,MENU_LENGHT,0,0);
		box(menuWin,0,0);

	}
	void Menu::startProces(){
		while(true){  
			werase(menuWin);
			box(menuWin,0,0);
			mvwprintw(menuWin,START_YM,MENU_X,"START");
			mvwprintw(menuWin,OPTION_Y,MENU_X,"OPTION");
			mvwprintw(menuWin,RECORDS_Y ,MENU_X,"RECORDS");
			mvwprintw(menuWin,kursY,KURSOE_X ,"<-");
			input();
			wrefresh(menuWin);
		}
	}

	void Menu::start(){
		delwin(menuWin);
		winIsOpen = false;
		game.startGame();
	}

	void Menu::option(){
		
	}
	
	void Menu::records(){
		/*std::vector<int> chemps;
		pushRecords(chemps);
		prinChemps(chemps);	*/
	}

	void Menu::prinChemps(std::vector<int>& chemps){
		for(int i = 0 ; i < chemps.size(); ++i){
			mvwaddch(menuWin, START_Y+i ,MENU_X,static_cast<chtype>(chemps[i]));
		}
	}

	void Menu::input(){
		switch(getch()){
			case 'w':
				if(kursY == START_YM){
					kursY = RECORDS_Y;
				}else{
					kursY--;
				}
				break;
			case 's':
				if(kursY == RECORDS_Y){
					kursY = START_YM;
				}else{
					kursY++;
				}
				break;
			case 10:
				switch(kursY){
					case START_YM:
						start();
						break;
					case OPTION_Y:
						option();
						break;
					case RECORDS_Y:
						records();
						break;
					}
				break;

		}
	}

	Menu::~Menu(){
		if(winIsOpen){
			delwin(menuWin);
		}
    	endwin(); 
	}

