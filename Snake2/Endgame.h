#pragma once
#include "board.h"
class Endgame :
	public Board
{
public:
	Endgame(short int *l, int *r, std::vector<ALLEGRO_FONT*> *f);
	~Endgame(void);

	void draw();
};
