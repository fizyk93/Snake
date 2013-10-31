#include "Snake.h"
#include "Allegro.h"


Snake::Snake(int x, int y)
{
	unit = 20;
	for(int i = 0; i<6; i++)
    {
        snake.push_front(Point(x,y,unit));
        x+=unit;
    }
}


Snake::~Snake(void)
{
}

std::list<Point>::iterator Snake::head()
{
	return snake.begin();
}

std::list<Point>::iterator Snake::tail()
{
	return snake.end();
}

void Snake::update(Direction dir)
{
	switch (dir)
	{
	case UP:
		snake.push_front(Point(snake.front().getX(), addModulo(snake.front().getY()-unit,30*unit)));
		snake.pop_back();
		break;
	case RIGHT:
		snake.push_front(Point(addModulo(snake.front().getX()+unit, 48*unit), snake.front().getY()));
		snake.pop_back();
		break;
	case DOWN:
		snake.push_front(Point(snake.front().getX(), addModulo(snake.front().getY()+unit, 30*unit)));
		snake.pop_back();
		break;
	case LEFT:
		snake.push_front(Point(addModulo(snake.front().getX()-unit,48*unit), snake.front().getY()));
		snake.pop_back();
		break;
	default:
		break;
	}
}

int Snake::addModulo(int sum, int m)
{
	if(sum == m) return 0;
	else if(sum < 0) return m-unit;
	else return sum;
}

void Snake::drawSnake()
{
	std::list<Point>::iterator it = head();
	it++;

	for(it; it != tail(); it++)
	{
		al_draw_filled_rectangle(160+it->getX()+1, 60+it->getY()+1, 160+it->getX()+20-1, 60+it->getY()+20-1, al_map_rgba_f(0,1,0, 1));
	}

	it = head();
	al_draw_filled_rectangle(160+it->getX()+1, 60+it->getY()+1, 160+it->getX()+unit-1, 60+it->getY()+unit-1, al_map_rgba_f(1,0.2,0.1, 2));

}

void Snake::growSnake()
{
	snake.push_front(snake.front());
}

bool Snake::inSnake(Point p)
{
	std::list<Point>::iterator it = this->head();
	it++;
	for(it; it != this->tail(); it++)
	{
		if(*it==p) return true;
	}

	return false;
}

bool Snake::crash()
{
	if(inSnake(*(head()))) return true;
	else return false;
}