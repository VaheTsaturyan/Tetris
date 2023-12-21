#ifndef GAME_LOGIC
#define GAME_LOGIC

#include <algorithm>
#include <chrono>
#include <vector>


#include "block.h"
#include "records.h"


namespace {
	using paint = int;
	using unit = bool;
	using size = size_t;
	using twoDimensionalVector = std::vector<std::vector<unit>>;
	inline const size BORD_LENGHT = 11; 
	inline const size BORD_HEIGHT = 20;
	inline const size ADD_POINT = 2;
	inline const size START_X = 4;
	inline const size START_Y = 0;
	inline const size LAST_ROW_INDEX = 0;
	inline const size LAST_COLUMN_INDEX = 10;
	inline const int NUMBER_OF_BLOCK_TYPES = 6;
}


class Bord{
public:
	Bord():bord(BORD_HEIGHT,std::vector<unit>(BORD_LENGHT,0)){
	}

	int IsFilledLine();
	bool bordFilles();
	void deleteRow();
	bool IsTtheLineFull(size rowIndex);


	twoDimensionalVector bord;
};



class game{
public:
	game();

	size getX();
	size getY();
	int getPoint();
	paint getColor();
	unit getBordUnit(int i, int j);
	unit getFigurUnit(int i, int j);
	size getFigurHeight()const;
	size getFigurLenght()const;
	bool gameOver();
	void newFigur();
	void gameDeleteRow();
	//void addRecords();
	void blockGoLeft();
	void blockGoRight();
	void blockGoDawn();
	//void ChempsPush();
	void flipBlock();//
	bool blockMoveDelay();

private:
	void addPoint();
	void addFigur();//
	void randFigurs();
	bool therIsRight();
	bool thereIsLeft();
	bool therIsDown();
	bool upsideDown(const matrix& temp);

private:
	Bord bordGame;
	std::vector<block*> blocks;
	//std::vector<int> chemps;
	block* figur;
	size x;
	size y;
	int point;
	paint col;
};

#endif