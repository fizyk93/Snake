#pragma once
#include "Object.h"
#include "Allegro.h"

class Board
	:public Object
{
public:
	int sizeX, sizeY;
	
	Board(int x, int y, short int *l, int *r, std::vector<ALLEGRO_FONT*> *f);
	~Board(void);
	virtual void draw();
	virtual void update();


protected:
	short *level;
	int *result;
	char levelStr[3];
	char resultStr[5];
	int x0, x1, y0, y1;
	std::vector<ALLEGRO_FONT*> *font;

};

