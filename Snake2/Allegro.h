#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_native_dialog.h"
#include <vector>



class Allegro
{
public:

	static const int FPS = 5.0; 
	static const int WindowWidth = 1280, WindowHeight = 720; 

	enum Font
	{
		BIG, SMALL, BOLDB, BOLDS
	};

	ALLEGRO_DISPLAY *display;
	std::vector<ALLEGRO_FONT*> font;
	int fontCount;
	ALLEGRO_DISPLAY_MODE disp_data;
	ALLEGRO_BITMAP *icon;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_EVENT events;


	Allegro(void);
	~Allegro(void);

	virtual void mainLoop() = 0;

	int loadAllegro();
	void quitAllegro();

private:
	int displaySetUp();
	int addonInit();
	int fontInstall();
	int eventsInit();

};
