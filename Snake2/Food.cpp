#include "Food.h"
#include "Allegro.h"

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