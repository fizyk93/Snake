#pragma once
#include "food.h"
#include <list>
using namespace std;
class ExtraFood :
	virtual public Food
{
public:

	static int time;
	static bool active;

	list<Food> elements;

	~ExtraFood(void);

	bool operator== (Snake& s);

	virtual void update() = 0;

protected:
	ExtraFood(void);

};

