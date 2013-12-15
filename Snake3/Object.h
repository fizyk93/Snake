#pragma once
class Object
{
public:
	
	static int adjustX, adjY;
	
	Object(void);
	~Object(void);

	virtual void update() = 0;
	virtual void draw() = 0;

	static void adjPos(int w, int h);

protected: 
	static  int sizeX, sizeY;

};