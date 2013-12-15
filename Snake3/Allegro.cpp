#include "Allegro.h"
#include "AllegroError.h"

#include <iostream>


Allegro::Allegro(void)
{
	fontCount = 0;
	display = NULL;
	timer = NULL;
	event_queue = NULL;

}


Allegro::~Allegro(void)
{
	
}

void Allegro::loadAllegro()
{
	if(!al_init())
	{
		throw(AllegroError(0, "Blad wczytywania Allegro"));
	}

	displaySetUp();
	addonInit();
	fontInstall();
	eventsInit();

}

void Allegro::quitAllegro()
{
	if(display)		al_destroy_display(display);
	if(timer)		al_destroy_timer(timer);
	if(event_queue)	al_destroy_event_queue(event_queue);
}

void Allegro::addonInit()
{
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
}


void Allegro::fontInstall()
{
	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\cour.ttf", 60, 0));
	if(!font[fontCount++])
	{
		throw(AllegroError(2, "Blad wczytywania czcionki: cour.ttf"));
	}


	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\cour.ttf", 30, 0));
	if(!font[fontCount++])
	{
		throw(AllegroError(2, "Blad wczytywania czcionki: cour.ttf"));
	}

	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\courbd.ttf", 60, 0));
	if(!font[fontCount++])
	{
		throw(AllegroError(2, "Blad wczytywania czcionki: courbd.ttf"));
	}

	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\courbd.ttf", 30, 0));

	if(!font[fontCount++])
	{
		throw(AllegroError(2, "Blad wczytywania czcionki: cour.ttfbd"));
	}
}

void Allegro::eventsInit()
{
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);
}

void Allegro::displaySetUp()
{
    al_get_display_mode(al_get_num_display_modes()-1, &disp_data);

	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	std::cout << "Width: " << disp_data.width << "\nHeight: " << disp_data.height << "\nFormat: " << disp_data.format << "\nRefresh rate: " << disp_data.refresh_rate << std::endl;


	WindowWidth = disp_data.width;
	WindowHeight = disp_data.height;
	display = al_create_display(WindowWidth, WindowHeight);

	std::cout << WindowHeight;

	if(!display)
		throw(AllegroError(1, "Blad wczytywania Allegro Display"));

}