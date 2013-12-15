#include "Food.h"
#include "Allegro.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

int Food::boardX = 0;
int Food::boardY = 0;

void Food::setBoard(int x, int y)
{
	Food::boardX = x;
	Food::boardY = y;
}
Food::Food(int sizeX, int sizeY, int u)
	: Point(u)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	srand(time(NULL));
	x = 20*(rand()%sizeX);
    y = 20*(rand()%sizeY);
	value = 1;
	srand(time(NULL));
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
	
	do
	{
		tmpx = 20*(rand()%sizeX);
		tmpy = 20*(rand()%sizeY);

	}while(x == tmpx && y == tmpy);

	x=tmpx;
	y=tmpy;

}

void Food::draw()
{
	al_draw_rectangle(adjustX+x+6, adjY+y+50+6, adjustX+x+unit-6, adjY+y+50+unit-6, al_map_rgb(0,0,0), 4);
}

bool Food::operator== (Snake& s)
{
	bool ans = false;
	switch (s.dir)
	{
	case UP:
		if(y == 20*(boardY-1))
			ans = (x == s.head()->getX() && 0 == s.head()->getY())?true:false;
		else
			ans = (x == s.head()->getX() && y+unit == s.head()->getY())?true:false;		
		break;
	case RIGHT:
		if(x == 0)
			ans = (20*(boardX-1) == s.head()->getX() && y == s.head()->getY())?true:false;
		else
			ans = (x-unit == s.head()->getX() && y == s.head()->getY())?true:false;
		break;
	case DOWN:
		if(y == 0)
			ans = (x == s.head()->getX() && 20*(boardY-1) == s.head()->getY())?true:false;
		else
			ans = (x == s.head()->getX() && y-unit == s.head()->getY())?true:false;	
		break;
	case LEFT:
		if(x == 20*(boardX-1))
			ans = (0 == s.head()->getX() && y == s.head()->getY())?true:false;
		else
			ans = (x+unit == s.head()->getX() && y == s.head()->getY())?true:false;
		break;
	default:
		break;
	}
	
	
	return ans;
}