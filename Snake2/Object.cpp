#include "Object.h"


int Object::adjX=0;
int Object::adjY=0;
int Object::sizeX=48;
int Object::sizeY=30;


Object::Object(void)
{
}


Object::~Object(void)
{
}

void Object::adjPos(int w, int h)
{
	Object::adjX = (w - sizeX*20)/2;
	Object::adjY = (h - (sizeY+4)*20)/2;
}