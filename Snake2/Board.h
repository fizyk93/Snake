#pragma once
class Board
{
public:
	int sizeX, sizeY;
	
	Board(int x, int y);
	~Board(void);
	void drawBoard();

protected:
	int x0, x1, y0, y1;

};

