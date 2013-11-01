#include <iostream>
#include <cstdlib>
#include "Allegro.h"
#include "Game.h"
#include "Point.h"
#include "Snake.h"

using namespace std;


int main(int argc, char **argv)
{
	Game* game = new Game();
	
	game->loadAllegro();
	
	game->mainLoop();

	game->quitAllegro();


	delete game;
	

	return 0;

}