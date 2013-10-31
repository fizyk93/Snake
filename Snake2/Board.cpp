#include "Board.h"




Board::Board(int x, int y, short int *l, int *r, std::vector<ALLEGRO_FONT*> *f)
{

	sizeX = x;
	sizeY = y;
	x0 = 160;
	y0 = 60;
	x1 = 20*x + x0;
	y1 = 20*y +y0;
	level = l;
	result = r;
	font = f;
}


Board::~Board(void)
{
}

void Board::draw()
{
	
	al_draw_rectangle(x0-2, y0-2, x1+2, y1+2, al_map_rgb(128,128,128), 4);
	_itoa_s((int)*level+1, levelStr, 3, 10);
	_itoa_s(*result, resultStr, 5, 10);
	al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), 370, 10, ALLEGRO_ALIGN_CENTRE, "Wynik: ");
    al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), 450, 10, ALLEGRO_ALIGN_CENTRE, resultStr);
    al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), 640, 10, ALLEGRO_ALIGN_CENTRE, "Poziom: ");
    al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), 720, 10, ALLEGRO_ALIGN_CENTRE, levelStr);
}

void Board::update()
{
}
