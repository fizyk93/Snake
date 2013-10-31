#pragma once
#include "point.h"

class Food :
	public Point
{
public:
	Food(int sizeX, int sizeY, int u = 20);
	~Food(void);

	void updateFood();

private:
	int sizeX, sizeY;

};

