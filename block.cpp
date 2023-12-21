#include "block.h"

	block::block(const matrix& Block){
		this->Block = Block;
	}


	matrix block::turnTheFigureOver(){
		matrix matrixTemp = Block ;
		for(int i = 0; i < getBlockHeight(); ++i){
			for(int j = 0; j < getBlockLenght(); ++j){
				matrixTemp[j][getBlockHeight() - 1 -i] = Block[i][j]; 				
			}
		}
		return matrixTemp;
	}

	void block::setBlock(const matrix& value){
		this-> Block = value;
	}

	unitB block::getUNIT(int i, int j)const{
		return Block[i][j];
	}

	int block::getBlockHeight()const{
		return Block.size();
	}

	int block::getBlockLenght()const{
		return Block[0].size();
	}

	int block::theLowestPoint(){
		for(int i = this->getBlockHeight(); i > 0 ; --i){
			for(int j = 0; j < this->getBlockLenght(); ++j){
				if(Block[i-1][j]){
					return i;
				}
			}
		}
		return getBlockHeight();
	}

	int block::everyRightPoint(){
		for(int i = this->getBlockLenght(); i > 0 ; --i){
			for(int j = 0; j < this->getBlockHeight(); ++j){
				if(Block[j][i-1]){
					return i;
				}
			}
		}
		return getBlockLenght();
	}


	int block::everyLeftPoint(){
		for(int i = 0;i < this->getBlockLenght(); ++i){
			for(int j = 0; j < this->getBlockHeight(); ++j){
				if(Block[j][i]){
					return i+1;
				}
			}
		}
		return 1;
	}


	matrix I_block::turnTheFigureOver(){
		matrix matrixTemp;
		if(Block.size() == 4){
			matrixTemp = {{1,1,1,1}};
		}else if (Block.size() == 1){
			matrixTemp = {	{1},
							{1},
							{1},
							{1}};
			
		}
		return matrixTemp;
	}