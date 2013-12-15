#include <iostream>
#include <cstdlib>
#include "Allegro.h"
#include "Game.h"
#include "Point.h"
#include "Snake.h"
#include "AllegroError.h"

using namespace std;


int main(int argc, char **argv)
{
	Game* game = new Game();
	
	try
	{
	game->loadAllegro();

	game->mainLoop();

	game->quitAllegro();

	}
	catch(AllegroError error)
	{
		game->quitAllegro();

		al_show_native_message_box(NULL, "BLAD", "", error.errorMessage, NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	
	delete game;
	

	return 0;

}