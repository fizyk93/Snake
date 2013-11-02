#pragma once

#include <list>
#include "Point.h"
#include "Object.h"


class Snake
	: public Object
{
public:

	Direction dir;

	Snake(int x = 100, int y = 100);
	~Snake(void);

	void update();

	std::list<Point>::iterator head();

	std::list<Point>::iterator tail();

	void draw();

	void growSnake();

	bool inSnake(Point p);
	bool inSnake(std::list<Point>& l);

	bool crash();
	
private:

	std::list<Point> snake;
	int addModulo(int sum, int m);
	int unit;

	
};

