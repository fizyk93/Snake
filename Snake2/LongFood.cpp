#include "LongFood.h"
#include "Allegro.h"


LongFood::LongFood(int sizeX, int sizeY, int u)
	:Food(sizeX-3, sizeY, u)
{
	time = 0;
	value = 3;
	active = false;
	Food tmp[] = {Food(x,y), Food(x+unit, y), Food(x+2*unit, y), Food(x+3*unit,y)};
	elements.assign(tmp, tmp+4);
}


LongFood::~LongFood(void)
{
}

void LongFood::draw()
{
	al_draw_filled_rectangle(adjustX+x+0, adjustY+y+50+0, adjustX+x+4*unit-0, adjustY+y+50+unit-0, al_map_rgb(255,240,0));
}

void LongFood::update()
{
	this->Food::update();
	Food tmp[] = {Food(x,y), Food(x+unit, y), Food(x+2*unit, y), Food(x+3*unit,y)};
	elements.assign(tmp, tmp+4);
}