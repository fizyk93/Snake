#pragma once
#include "food.h"
#include <list>
using namespace std;

class BigFood :
	public Food
{
public:

	static int time;
	static bool active;
	
	BigFood(int sizeX, int sizeY, int u = 20);
	~BigFood(void);
	list<Food> elements;
	//bool operator== (Point& p);
	bool operator== (Snake& s);

	void draw();

	void update();
};
