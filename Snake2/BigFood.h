#pragma once
#include "food.h"
class BigFood :
	public Food
{
public:

	int time;

	BigFood(int sizeX, int sizeY);
	~BigFood(void);

	bool operator== (Point& p);
};
