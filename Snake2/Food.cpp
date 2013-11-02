#include "Food.h"
#include "Allegro.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

Food::Food(int sizeX, int sizeY, int u)
	: Point(u)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	srand(time(NULL));
	x = 20*(rand()%sizeX);
    y = 20*(rand()%sizeY);
	value = 1;
}

Food::Food(int x, int y)
{
	this->x = x;
	this->y = y;
	unit = 20;
}

Food::~Food(void)
{
}

void Food::update()
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

void Food::draw()
{
	al_draw_rectangle(adjX+x+6, adjY+y+50+6, adjX+x+unit-6, adjY+y+50+unit-6, al_map_rgb(0,0,0), 4);
}

bool Food::operator== (Snake& s)
{
	bool ans = false;
	switch (s.dir)
	{
	case UP:
		if(x == s.head()->getX() && y+unit == s.head()->getY()) ans = true;
		break;
	case RIGHT:
		if(x-unit == s.head()->getX() && y == s.head()->getY()) ans = true;
		break;
	case DOWN:
		if(x == s.head()->getX() && y-unit == s.head()->getY()) ans = true;
		break;
	case LEFT:
		if(x+unit == s.head()->getX() && y == s.head()->getY()) ans = true;
		break;
	default:
		break;
	}
	
	
	return ans;
}