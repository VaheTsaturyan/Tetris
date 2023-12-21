#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <vector>

namespace {
	using unitB = bool;
	using row = std::vector<unitB>;
	using matrix = std::vector<row>;
}

class block{
public:
	block(const matrix& Block);
	virtual matrix turnTheFigureOver();
	unitB getUNIT(int i, int j)const;
	int getBlockHeight()const;
	int getBlockLenght()const;
	void setBlock(const matrix& value);
	int theLowestPoint();
	int everyRightPoint();
	int everyLeftPoint();

	virtual ~block(){} ;
protected:
	matrix Block;

};


class I_block : public block{
public:
	I_block(): 
		block({	{1},
				{1},
				{1},
				{1}}){}

	matrix turnTheFigureOver() override;
protected:
};

class x2_block : public block{
public:
	x2_block(): 
		block({	{1,1},
				{1,1}}){}

	matrix turnTheFigureOver() override{
		return Block;
	}
protected:


};

class T_block : public block{
public:
	T_block(): 
		block({	{1,1,1},
				{0,1,0},
				{0,0,0}}){}
protected:


};


class L_block : public block{
public:
	L_block(): 
		block({	{0,1,0},
				{0,1,0},
				{0,1,1} }){}

protected:


};

class J_block : public block{
public:
	J_block(): 
		block({	{0,1,0},
				{0,1,0},
				{1,1,0}}){
			}
protected:


};


class S_block : public block{
public:
	S_block(): 
		block({	{0,1,0},
				{0,1,1},
				{0,0,1}}){
	}
protected:


};


class Z_block : public block{
public:
	Z_block(): 
		block({	{0,0,1},
				{0,1,1},
				{0,1,0}}){
		}
protected:


};





#endif // BLOCK_HPP