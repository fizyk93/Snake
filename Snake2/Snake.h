#pragma once

#include <list>
#include "Point.h"

class Snake
{
public:

	Direction dir;

	Snake(int x = 100, int y = 100);
	~Snake(void);

	void update(Direction dir);

	std::list<Point>::iterator head();

	std::list<Point>::iterator tail();

	void drawSnake();

	void growSnake();

	bool inSnake(Point p);

	bool crash();
	
private:

	std::list<Point> snake;
	int addModulo(int sum, int m);
	int unit;

	
};

