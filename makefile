all:
	g++ block.cpp gameLogic.cpp gameVisuals.cpp main.cpp menu.cpp records.cpp -lncurses


clean:
	rm tetris
