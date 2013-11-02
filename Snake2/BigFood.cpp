#include "BigFood.h"
#include "Allegro.h"
#include <iostream>

int BigFood::time = 0;

//bool BigFood::operator== (Snake& s)
//{
//	return (Food(x,y) == s || Food(x+unit,y) == s || Food(x,y+unit) ==s || Food(x+unit,y+unit)== s);
//
//}

bool BigFood::operator== (Snake& s)
{
	for(list<Food>::iterator it = elements.begin(); it != elements.end(); it++)
	{
		if(*it == s) return true;
		printf("food: (%d, %d)\t" , it->getX(), it->getY()); 
	}
	
	printf("snake: (%d, %d)\n", s.head()->getX(), s.head()->getY());
	
	return false;
}

BigFood::BigFood(int sizeX, int sizeY, int u)
	:Food(sizeX-1, sizeY-1, u)
{
	time = 0;
	value = 3;
	Food tmp[] = {Food(x,y), Food(x+unit, y), Food(x, y+unit), Food(x+unit,y+unit)};
	elements.assign(tmp, tmp+4);
}


BigFood::~BigFood(void)
{
}

void BigFood::draw()
{
	al_draw_filled_rectangle(adjX+x+0, adjY+y+50+0, adjX+x+2*unit-0, adjY+y+50+2*unit-0, al_map_rgb(250,210,0));
}

void BigFood::update()
{
	this->Food::update();
	Food tmp[] = {Food(x,y), Food(x+unit, y), Food(x, y+unit), Food(x+unit,y+unit)};
	elements.assign(tmp, tmp+4);
}