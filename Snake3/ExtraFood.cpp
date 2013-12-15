#include "ExtraFood.h"

int ExtraFood::time = 0;
bool ExtraFood::active = false;

ExtraFood::ExtraFood(void)
	:Food(-1, -1)
{
}


ExtraFood::~ExtraFood(void)
{
}


bool ExtraFood::operator== (Snake& s)
{
	for(list<Food>::iterator it = elements.begin(); it != elements.end(); it++)
	{
		if(*it == s) return true;
		//printf("food: (%d, %d)\t" , it->getX(), it->getY()); 
	}
	
	//printf("snake: (%d, %d)\n", s.head()->getX(), s.head()->getY());
	
	return false;
}