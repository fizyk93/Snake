#pragma once
#include "Object.h"


class Board
	:public Object
{
public:
	int sizeX, sizeY;
	
	Board(int x, int y, short int *l, int *r);
	~Board(void);
	virtual void draw();
	virtual void update();


protected:
	short *level;
	int *result;
	int x0, x1, y0, y1;

};

