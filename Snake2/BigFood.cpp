#include "BigFood.h"


bool BigFood::operator== (Point& p)
{
	return ((x == p.getX()) && (y == p.getY()));
}

BigFood::BigFood(int sizeX, int sizeY)
	:Food(sizeX, sizeY)
{
	time = 0;
}


BigFood::~BigFood(void)
{
}
