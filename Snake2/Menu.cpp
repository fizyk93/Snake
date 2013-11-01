#include "Menu.h"




Menu::Menu(short *l, int *r, std::vector<ALLEGRO_FONT*> *f)
	: Board(l, r, f) 
{
	option = 0;
}


Menu::~Menu(void)
{
}

void Menu::draw()
{
		_itoa_s(*level+1, levelStr, 3, 10);
		al_clear_to_color(al_map_rgb(255,255,255));
        al_draw_text(*(font->begin()+BIG), al_map_rgb(0,255,0), 470, 130, ALLEGRO_ALIGN_CENTRE, "Snake");
        al_draw_rectangle(340, 110, 610, 600, al_map_rgb(64,64,64), 5);
        al_draw_rectangle(630, 110, 900, 600, al_map_rgb(64,64,64), 5);
        al_draw_line( 370, 210, 580, 210, al_map_rgb(255,0,0), 4 );

		al_draw_text(*(font->begin()+BOLDS), color[0], 470, 230, ALLEGRO_ALIGN_CENTRE, "Nowa gra");
        al_draw_text(*(font->begin()+BOLDS), color[1], 470, 330, ALLEGRO_ALIGN_CENTRE, "Wznow");
        al_draw_text(*(font->begin()+BOLDS), color[2], 470, 430, ALLEGRO_ALIGN_CENTRE, "Poziom: ");
        al_draw_text(*(font->begin()+BOLDS), color[2], 540, 430, ALLEGRO_ALIGN_CENTRE, levelStr);
        al_draw_text(*(font->begin()+BOLDS), color[3], 470, 530, ALLEGRO_ALIGN_CENTRE, "Wyjscie");
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
