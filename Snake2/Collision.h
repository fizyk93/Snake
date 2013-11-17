#pragma once
#include "Snake.h"
#include "BigFood.h"
class Collision
{
public:
	~Collision(void);
	static bool Collision::inSnake(Snake& s, Point& p);
	
	static bool Collision::inSnake(Snake& s, std::list<Food>& l);



private:
	Collision(void);
	
};

