#include "BigFood.h"
#include "Allegro.h"
#include <iostream>




//bool BigFood::operator== (Snake& s)
//{
//	for(list<Food>::iterator it = elements.begin(); it != elements.end(); it++)
//	{
//		if(*it == s) return true;
//		printf("food: (%d, %d)\t" , it->getX(), it->getY()); 
//	}
//	
//	printf("snake: (%d, %d)\n", s.head()->getX(), s.head()->getY());
//	
//	return false;
//}

BigFood::BigFood(int sizeX, int sizeY, int u)
	:Food(sizeX-1, sizeY-1, u)
{
	time = 0;
	value = 3;
	active = false;
	Food tmp[] = {Food(x,y), Food(x+unit, y), Food(x, y+unit), Food(x+unit,y+unit)};
	elements.assign(tmp, tmp+4);
}


BigFood::~BigFood(void)
{
}

void BigFood::draw()
{
	al_draw_filled_rectangle(adjustX+x+0, adjustY+y+50+0, adjustX+x+2*unit-0, adjustY+y+50+2*unit-0, al_map_rgb(255,240,0));
}

void BigFood::update()
{
	this->Food::update();
	Food tmp[] = {Food(x,y), Food(x+unit, y), Food(x, y+unit), Food(x+unit,y+unit)};
	elements.assign(tmp, tmp+4);
}