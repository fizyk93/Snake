#pragma once
#include "Object.h"
#include "Allegro.h"

class Board
	:public Object
{
public:
	
	
	Board(short int *l, int *r, std::vector<ALLEGRO_FONT*> *f);
	~Board(void);
	virtual void draw();
	virtual void update();
	//static int adjX, adjY;
	//static void adjPos(int w, int h);


protected:
	int screenWidth, screenHeight;
	short *level;
	int *result;
	char levelStr[3];
	char resultStr[5];
	int x0, x1, y0, y1;
	std::vector<ALLEGRO_FONT*> *font;

private: 
	//static const int sizeX = 48, sizeY = 30;
	
};

