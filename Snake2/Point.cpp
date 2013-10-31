#include "Point.h"


#include <ctime>
#include <cstdlib>


Point::Point(int x, int y, int u)
{
	this->x = x;
	this->y = y;
}

Point::Point(int unit)
{
	this->unit=unit;
}


int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

bool Point::operator== (Point& p)
{
	return ((x == p.getX()) && (y == p.getY()));
}

