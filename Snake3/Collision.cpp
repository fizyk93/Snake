#include "Collision.h"


Collision::Collision(void)
{
}


Collision::~Collision(void)
{
}


bool Collision::inSnake(Snake& s, Point& p)
{
	std::list<Point>::iterator it = s.head();
	it++;
	for(it; it != s.tail(); it++)
	{
		if(*it==p) return true;
	}

	return false;
}

bool Collision::inSnake(Snake& s, std::list<Food>& l)
{
	std::list<Point>::iterator it = s.head();
	it++;
	for(it; it != s.tail(); it++)
	{
		for(std::list<Food>::iterator it2 = l.begin(); it2 != l.end(); it2++)
			if(*it==*it2) return true;
	}

	return false;
}