#pragma once
#include "point.h"
#include "Object.h"
#include <iostream>
#include "Snake.h"

class Food :
	public Point, public Object
{
public:
	Food(int sizeX, int sizeY, int u);
	~Food(void);

	void update();
	virtual void draw();
	int value;

	virtual bool operator== (Snake& s);

	Food(int x, int y);

private:
	int sizeX, sizeY;

};

