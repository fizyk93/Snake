#pragma once
#include <fstream>
#include "Allegro.h"

#include "Board.h"
#include "Point.h"
#include "Snake.h"
#include "Food.h"
#include "BigFood.h"

class Game
	:public Allegro
{
public:

	
	Food *food;
	Snake *snake;
	Board *board;
	Direction dir, tmpDir;
	float newInterval;
	int iter;
	

	ALLEGRO_COLOR color[4];
	int option;

	Game(void);
	~Game(void);

	int addModulo(int sum, int m);

	void mainLoop();

	void resetGame();



	



private:
	int sizeX, sizeY;
	bool draw, done, menu, endgame;
	static const float levels[10];
	short int currLevel;
	void loadLevel(int num);
	char levelStr[3];
	int result;
	char resultStr[5];
	

};
