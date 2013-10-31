#pragma once


enum Direction
{
	UP, RIGHT, DOWN, LEFT
};

class Point
{
public:

	Point(int unit = 1);
	Point(int x, int y, int unit = 1);

	int getX();

	int getY();

	int getUnit()
	{
		return unit;
	}
	

	virtual bool operator== (Point& p);
	
protected:
	int x, y;
	int unit;
};




