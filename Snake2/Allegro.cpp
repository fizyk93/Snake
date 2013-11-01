#include "Allegro.h"

#include <iostream>


Allegro::Allegro(void)
{
	fontCount = 0;
	display = NULL;
}


Allegro::~Allegro(void)
{
	
}

int Allegro::loadAllegro()
{
	if(!al_init())
	{
		al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania Allegro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	displaySetUp();
	addonInit();
	fontInstall();
	eventsInit();

	return 0;
}

void Allegro::quitAllegro()
{
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
}

int Allegro::addonInit()
{
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();

	return 0;
}

int Allegro::fontInstall()
{
	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\cour.ttf", 60, 0));
	if(!font[fontCount++])
	{
        al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania czcionki", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        getchar();
		return -1;
	}


	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\cour.ttf", 30, 0));
	if(!font[fontCount++])
	{
        al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania czcionki", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        getchar();
        return -1;
	}

	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\courbd.ttf", 60, 0));
	if(!font[fontCount++])
	{
        al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania czcionki", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        getchar();
        return -1;
	}

	font.push_back(al_load_ttf_font("C:\\WINDOWS\\Fonts\\courbd.ttf", 30, 0));

	if(!font[fontCount++])
	{
        al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania czcionki", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        getchar();
        return -1;
	}

	return 0;
}

int Allegro::eventsInit()
{
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_start_timer(timer);

	return 0;
}

int Allegro::displaySetUp()
{
    al_get_display_mode(al_get_num_display_modes()-1, &disp_data);

	//al_set_window_position(display, (disp_data.width-WindowWidth)/2, (disp_data.height-WindowHeight)/2-30);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	std::cout << "Width: " << disp_data.width << "\nHeight: " << disp_data.height << "\nFormat: " << disp_data.format << "\nRefresh rate: " << disp_data.refresh_rate;

	//display = al_create_display(WindowWidth, WindowHeight);
	//display = al_create_display(disp_data.width, disp_data.height);
	WindowWidth = disp_data.width;
	WindowHeight = disp_data.height;
	display = al_create_display(WindowWidth, WindowHeight);

	std::cout << WindowHeight;

	if(!display)
	al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania Allegro Display", NULL, ALLEGRO_MESSAGEBOX_ERROR);

    /*ALLEGRO_BITMAP *icon = al_load_bitmap("SnakeIcon.gif");
	if ( !icon )
	{
        al_show_native_message_box(NULL, "BLAD", "", "Blad wczytywania ikony", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		getchar();
		return -1;
	}

	al_set_display_icon(display, icon);
	*/

	return 0;
}