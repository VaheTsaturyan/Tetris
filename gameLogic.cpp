#include"gameLogic.h"


using SteadyClock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<SteadyClock>;

const std::chrono::milliseconds moveTime{500}; 
TimePoint moveStartTime;

//////////////////////////////////BORD//////////////////////////////////
bool Bord::deleteRow(){
	int nomberRow = IsFilledLine(); 
	if(nomberRow == -1){
		return false;
	}
	for(int i = nomberRow; i > LAST_ROW_INDEX ; --i ){
		bord[i] = bord[i-1];
	}
	bord[LAST_ROW_INDEX] = std::vector<unit>(BORD_LENGHT,false);
	return true;
}

int Bord::IsFilledLine(){
	for(int i = BORD_HEIGHT-1; i >= 0; --i){
		if(IsTtheLineFull(i)){
			return i;
		}
	}
	return -1;
}

bool Bord::IsTtheLineFull(size rowIndex){
	for(int i = 0; i < BORD_LENGHT; ++i){
		if (!bord[rowIndex][i]){
			return false;
		}
	}
	return true;
}

bool Bord::bordFilles(){
	for(int i = 0; i < BORD_LENGHT; ++i){
		if(bord[LAST_ROW_INDEX][i]){
			return true;
		}
	}
	return false;
}







////////////////////////////////////GAME_LOGIC/////////////////////////////

game::game():x(START_X),y(START_Y),point(0){
	blocks.push_back(new I_block);
	blocks.push_back(new x2_block);
	blocks.push_back(new T_block);
	blocks.push_back(new L_block);
	blocks.push_back(new J_block);
	blocks.push_back(new S_block);
	blocks.push_back(new Z_block);

	TimePoint  moveStartTime = std::chrono::steady_clock::now();
}


size game::getX(){
	return x;
}

size game::getY(){
	return y;
}

size game::getFigurHeight()const{
	return figur->getBlockHeight();
}

size game::getFigurLenght()const{
	return figur->getBlockLenght();
}

int game::getPoint(){
	return point;
}

unit game::getBordUnit(int i, int j){
	return bordGame.bord[i][j];
}

unit game::getFigurUnit(int i, int j){
	return figur->getUNIT(i,j);
}




////////////////////////
/*void game::addRecords(){
		ChempsPush();
		int caunt = chemps.size();
		if(caunt > NUMBER_OF_RECORD_STORED){
			caunt = NUMBER_OF_RECORD_STORED;
		}
		for(int i = 0; i < caunt; ++i){
			saveToFile(chemps[i]);
		}
}*/
/*void game::ChempsPush(){
		int newChemp(point);
		chemps.push_back(newChemp);
		std::sort(chemps.begin(),chemps.end());
}*/
////////////////////////


void game::blockGoLeft(){
	if(thereIsLeft()){
		this->x--;
	}else{
		return;
	}
}

bool game::thereIsLeft(){
	int leftPoint = figur->everyLeftPoint();
	if(x + leftPoint - 1 == 0){
		return false;
	}
	for(int i = leftPoint; i < figur->getBlockLenght()+1; ++i ){
		for( int j = 0; j < figur->theLowestPoint(); ++j){
			if(bordGame.bord[y+j][x+i-2] && figur->getUNIT(j,i-1)){
				return false;
			}

		}
	}	

	return true;
}

void game::blockGoRight(){
	if(therIsRight()){
		this->x++;
	}else{
		return;
	}
}

bool game::therIsRight(){
	int rightPoint = figur->everyRightPoint();

	if((x + rightPoint) == (BORD_LENGHT)){
		return false;
	}
	for(int i = rightPoint; i > 0; --i ){
		for( int j = 0; j < figur->theLowestPoint(); ++j){
			if(bordGame.bord[y+j][x+i] && figur->getUNIT(j,i-1)){
				return false;
			}

		}
	}	
	
	return true;
}

void game::blockGoDawn(){
	if(therIsDown()){
		this->y++;
	}else{
		newFigur();
	}
}

bool game::therIsDown(){

	int lowesPoint = figur->theLowestPoint();
	if((y + lowesPoint) == (BORD_HEIGHT)){
		return false;
	}
	for(int i = lowesPoint; i > 0; --i ){
		for( int j = 0; j < figur->everyRightPoint(); ++j){
			if(bordGame.bord[y+i][x+j] && figur->getUNIT(i-1,j)){
				return false;
			}

		}
	}
	return true;
}

bool game::gameOver(){
	if(bordGame.bordFilles()){
		//addRecords();
		return true;
	}
	return false;
}




paint game::getColor(){
	return this->col;
}

void game::flipBlock(){
	matrix temp = figur->turnTheFigureOver();
	if(upsideDown(temp)){
		figur->setBlock(temp);
	}else{
		return;
	}
}

bool game::upsideDown(const matrix& temp){
	/*for(int i = 0; i < temp.size(); ++i){
		for(int j = 0; j < temp[i].size(); ++j){			
			if(temp[i][j] == true && bordGame.bord[i][j] == true ){
				return false;
			}
		}
	}*/
	return true;
}

void game::newFigur(){
	col = rand()%5+1;
	addFigur();
	randFigurs();
	//addPoint();
	
}

void game::gameDeleteRow(){
	if(bordGame.deleteRow()){
		addPoint();
	}
}

void game::addFigur(){
	for(int i = 0; i < figur->getBlockHeight();++i){
		for(int j = 0; j < figur->getBlockLenght(); ++j)
		{
			if(figur->getUNIT(i,j)){
				bordGame.bord[y+i][x+j] = true;
			}
		}
	}
	//bordGame.deleteRow();

}

void game::addPoint(){
	this->point += ADD_POINT;
}

void game::randFigurs(){
	this->x = START_X;
	this->y = START_Y; 
	this->figur = blocks[rand()%(NUMBER_OF_BLOCK_TYPES+1)];
}

bool game::blockMoveDelay() {
	auto currentTime = std::chrono::steady_clock::now();

	if (currentTime - moveStartTime >= moveTime) {        
        moveStartTime = currentTime;

		return true;
    }

	return false;
}

