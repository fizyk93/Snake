#pragma once
#include "point.h"
#include "Object.h"

class Food :
	public Point, public Object
{
public:
	Food(int sizeX, int sizeY, int u = 20);
	~Food(void);

	void update();
	void draw();

private:
	int sizeX, sizeY;

};

