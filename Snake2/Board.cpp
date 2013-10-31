#include "Board.h"
#include "Allegro.h"


Board::Board(int x, int y, short int *l, int *r)
{

	sizeX = x;
	sizeY = y;
	x0 = 160;
	y0 = 60;
	x1 = 20*x + x0;
	y1 = 20*y +y0;
	level = l;
	result = r;
}


Board::~Board(void)
{
}

void Board::draw()
{
	al_draw_rectangle(x0-2, y0-2, x1+2, y1+2, al_map_rgb(128,128,128), 4);
}

void Board::update()
{
}
