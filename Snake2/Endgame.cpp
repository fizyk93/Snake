#include "Endgame.h"
#include "Allegro.h"


Endgame::Endgame(short int *l, int *r, std::vector<ALLEGRO_FONT*> *f)
	:Board(l, r, f)
{
}


Endgame::~Endgame(void)
{
}


void Endgame::draw()
{
	Board::draw();
	 _itoa_s(*result, resultStr, 5, 10);

    al_draw_filled_rectangle(adjustX, adjustY+50, adjustX+20*sizeX, adjustY+20*sizeY+50, al_map_rgba_f(0.7,0.7,0.7, 0.1));
            
    al_draw_text(*(font->begin()+BIG), al_map_rgb(128,128,128), adjustX+460, adjustY+250, ALLEGRO_ALIGN_CENTRE, "Koniec gry!");
    al_draw_text(*(font->begin()+BIG), al_map_rgb(128,128,128), adjustX+440, adjustY+350, ALLEGRO_ALIGN_CENTRE, "Wynik: ");
    al_draw_text(*(font->begin()+BIG), al_map_rgb(128,128,128), adjustX+610, adjustY+350, ALLEGRO_ALIGN_CENTRE, resultStr);
    al_flip_display();
}