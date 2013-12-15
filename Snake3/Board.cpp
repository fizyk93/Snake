#include "Board.h"
#include <iostream>
using namespace std;

//int Board::=0;
//int Board::adjY=0;

Board::Board(short int *l, int *r, std::vector<ALLEGRO_FONT*> *f)
{
	level = l;
	result = r;
	font = f;
}


Board::~Board(void)
{
}

void Board::draw()
{
	
	al_draw_rectangle(adjustX-2, adjY+50-2, adjustX+20*sizeX+2, adjY+20*sizeY+50+2, al_map_rgb(128,128,128), 4);
	_itoa_s((int)*level+1, levelStr, 3, 10);
	_itoa_s(*result, resultStr, 5, 10);
	al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), adjustX+370, adjY, ALLEGRO_ALIGN_CENTRE, "Wynik: ");
    al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), adjustX+450, adjY, ALLEGRO_ALIGN_CENTRE, resultStr);
    al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), adjustX+640, adjY, ALLEGRO_ALIGN_CENTRE, "Poziom: ");
    al_draw_text(*(font->begin()+SMALL), al_map_rgb(128,128,128), adjustX+720, adjY, ALLEGRO_ALIGN_CENTRE, levelStr);
}

void Board::update()
{
}

//void Board::adjPos(int w, int h)
//{
//	Board:: = (w - sizeX*20)/2;
//	Board::adjY = (h - sizeY*20)/2;
//}