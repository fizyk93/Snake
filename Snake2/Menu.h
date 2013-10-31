#pragma once
#include "board.h"

class Menu :
	public Board
{
public:
	Menu(int x, int y, short int *l, int *r, std::vector<ALLEGRO_FONT*> *f);
	~Menu(void);

	void draw();
	void update();
	int option;

private:

	ALLEGRO_COLOR color[4];
	
};

