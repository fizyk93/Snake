#pragma once
#include "Extrafood.h"
class LongFood :
	public ExtraFood
{
public:

	LongFood(int sizeX, int sizeY, int u = 20);
	~LongFood(void);

	//bool operator== (Point& p);
	

	void draw();

	void update();
};

