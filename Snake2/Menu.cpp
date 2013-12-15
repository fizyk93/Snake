#include "Menu.h"
#include <iostream>




Menu::Menu(short *l, int *r, std::vector<ALLEGRO_FONT*> *f, int *t)
	: Board(l, r, f) 
{
	option = 0;
	results = t;
}


Menu::~Menu(void)
{
}

void Menu::draw()
{
		_itoa_s(*level+1, levelStr, 3, 10);
		al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_text(*(font->begin()+BIG), al_map_rgb(0,255,0), adjustX+300, adjustY+130, ALLEGRO_ALIGN_CENTRE, "Snake");
        al_draw_rectangle(adjustX+170, adjustY+100, adjustX+440, adjustY+590, al_map_rgb(64,64,64), 5);
        al_draw_rectangle(adjustX+460, adjustY+100, adjustX+760, adjustY+590, al_map_rgb(64,64,64), 5);
        al_draw_line( adjustX+200, adjustY+200, adjustX+410, adjustY+200, al_map_rgb(255,0,0), 4 );

		al_draw_text(*(font->begin()+BOLDS), color[0], adjustX+300, adjustY+230, ALLEGRO_ALIGN_CENTRE, "Nowa gra");
        al_draw_text(*(font->begin()+BOLDS), color[1], adjustX+300, adjustY+330, ALLEGRO_ALIGN_CENTRE, "Wznow");
        al_draw_text(*(font->begin()+BOLDS), color[2], adjustX+300, adjustY+430, ALLEGRO_ALIGN_CENTRE, "Poziom: ");
        al_draw_text(*(font->begin()+BOLDS), color[2], adjustX+370, adjustY+430, ALLEGRO_ALIGN_CENTRE, levelStr);
        al_draw_text(*(font->begin()+BOLDS), color[3], adjustX+300, adjustY+530, ALLEGRO_ALIGN_CENTRE, "Wyjscie");

		al_draw_text(*(font->begin()+BOLDS), al_map_rgb(128,128,128), adjustX+600, adjustY+130, ALLEGRO_ALIGN_CENTRE, "Najlepsze");
		al_draw_text(*(font->begin()+BOLDS), al_map_rgb(128,128,128), adjustX+600, adjustY+160, ALLEGRO_ALIGN_CENTRE, "wyniki:");

		for(int i = 0; i<10; i++)
		{
			_itoa_s(i+1, nrStr, 3, 10);
			_itoa_s(results[i], resultStr, 5, 10);
			al_draw_text(*(font->begin()+BOLDS), al_map_rgb(128,128,128), adjustX+530, adjustY+220+35*i, ALLEGRO_ALIGN_RIGHT, nrStr);
            al_draw_text(*(font->begin()+BOLDS), al_map_rgb(128,128,128), adjustX+545, adjustY+220+35*i, ALLEGRO_ALIGN_RIGHT, ".");
			al_draw_text(*(font->begin()+BOLDS), al_map_rgb(128,128,128), adjustX+640, adjustY+220+35*i, ALLEGRO_ALIGN_RIGHT, resultStr);
		}

}

void Menu::update()
{
			for(int i = 0; i < 4; i++)
            color[i] = al_map_rgb(128,128,128);

            switch(option)
            {
                case 0:
                    color[0] = al_map_rgb(128,128,255);
                    break;
                case 1:
                    color[1] = al_map_rgb(128,128,255);
                    break;
                case 2:
                    color[2] = al_map_rgb(128,128,255);
                    break;
                case 3:
                    color[3] = al_map_rgb(128,128,255);
                    break;
            }
}
