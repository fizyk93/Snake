#include "Food.h"

#include <ctime>
#include <cstdlib>

Food::Food(int sizeX, int sizeY, int u)
	: Point(u)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	srand(time(NULL));
	x = 20*(rand()%sizeX);
    y = 20*(rand()%sizeY);
}


Food::~Food(void)
{
}

void Food::updateFood()
{
	int tmpx, tmpy;
	srand(time(NULL));
	do
	{
		tmpx = 20*(rand()%sizeX);
		tmpy = 20*(rand()%sizeY);
	}while(x == tmpx || y == tmpy);

	x=tmpx;
	y=tmpy;

}