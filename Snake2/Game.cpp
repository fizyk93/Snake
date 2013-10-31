#include "Game.h"
#include <iostream>


Game::Game(void)
{
	sizeX = 48;
	sizeY = 30;
	board = new Board(48, 30);
	snake = NULL;
	food = new Food(sizeX, sizeY);
	done = false;
	draw = false;
	menu = true;
	option = 0;
	tmpDir = RIGHT;
	currLevel = 0;
	result = 0;
	endgame = false;
	
}

const float Game::levels[10] = {5, 6, 7.2, 8.6, 10.3, 12.4, 14.9, 17.9, 21.4, 25.7};

Game::~Game(void)
{
	delete board;
	if(snake) delete snake;
	delete food;
}

void Game::loadLevel(int num)
{
	al_set_timer_speed(timer, 1 / levels[num]);
}

int Game::addModulo(int sum, int m)
{
	if(sum == m) return 0;
	else if(sum < 0) return m-1;
	else return sum;
}

void Game::resetGame()
{
	if(snake) delete snake;
	snake = new Snake();
	tmpDir = RIGHT;
	result = 0;
	menu = false;
	draw = true;
	
}


void Game::mainLoop()
{
	while(!done)
    {

		al_wait_for_event(event_queue, &events);
		al_get_keyboard_state(&keyState);

		

		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
			draw = false;
		}
		else if(events.type == ALLEGRO_EVENT_KEY_DOWN && menu)
		{
			switch(events.keyboard.keycode)
            {
				case ALLEGRO_KEY_UP:
                    option = addModulo(--option, 4);
                    break;
                case ALLEGRO_KEY_DOWN:
                    option = addModulo(++option, 4);
                    break;
                case ALLEGRO_KEY_ENTER:
                    if(option == 0)
						resetGame();
					else if(option == 1)
                    {
						if(!snake) resetGame();
						else
						{
							draw = true;
							menu = false;
						}
                        
                    }
                    else if(option == 3)
                        done = true;
                    break;
				case ALLEGRO_KEY_RIGHT:
					if(option == 2)
					{
						currLevel = addModulo(++currLevel, 10);
						loadLevel(currLevel);
					}
					break;
				case ALLEGRO_KEY_LEFT:
					if(option == 2)
					{
						currLevel = addModulo(--currLevel, 10);
						loadLevel(currLevel);
					}
					break;
				case ALLEGRO_KEY_ESCAPE:
                    draw=true;
					menu=false;
                    break;
				default: 
					break;
			}
		}
		else if(events.type == ALLEGRO_EVENT_KEY_DOWN && draw)
        {
            switch(events.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                    if(dir == DOWN) break;
                    tmpDir = UP;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(dir == LEFT) break;
                    tmpDir = RIGHT;
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(dir == UP) break;
                    tmpDir = DOWN;
                    break;
                case ALLEGRO_KEY_LEFT:
                    if(dir == RIGHT) break;
                    tmpDir = LEFT;
					break;
				case ALLEGRO_KEY_T:
					currLevel = addModulo(++currLevel, 10);
					loadLevel(currLevel);
                    break;
				case ALLEGRO_KEY_ESCAPE:
                    menu=true;
                    break;
				default: 
					break;

            }
        }
		else if(events.type == ALLEGRO_EVENT_KEY_DOWN && !draw && !menu)
        {
            switch(events.keyboard.keycode)
            {
				case ALLEGRO_KEY_ESCAPE:
                    menu=true;
                    break;
				case ALLEGRO_KEY_ENTER:
					menu = true;
					break;
			}
		}
		else if (events.type == ALLEGRO_EVENT_TIMER && draw)
		{
			if(snake->crash())
			{
				draw = false;
				endgame = true;
			}

            dir = tmpDir;
			
			if(*food == *snake->head())
			{
				result += (currLevel+1);
				do
				{
				food->updateFood();
				}while(snake->inSnake(*food));

				snake->growSnake();

			}


            if(draw) snake->update(dir);
		}
		


		//al_clear_to_color(al_map_rgb(255,255,255));
		
		if(menu)
		{
			draw = false;
			_itoa_s(currLevel+1, levelStr, 3, 10);
			al_clear_to_color(al_map_rgb(255,255,255));
            al_draw_text(font[BIG], al_map_rgb(0,255,0), 470, 130, ALLEGRO_ALIGN_CENTRE, "Snake");
            al_draw_rectangle(340, 110, 610, 600, al_map_rgb(64,64,64), 5);
            al_draw_rectangle(630, 110, 900, 600, al_map_rgb(64,64,64), 5);
            al_draw_line( 370, 210, 580, 210, al_map_rgb(255,0,0), 4 );

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

			al_draw_text( font[BOLDS], color[0], 470, 230, ALLEGRO_ALIGN_CENTRE, "Nowa gra");
            al_draw_text( font[BOLDS], color[1], 470, 330, ALLEGRO_ALIGN_CENTRE, "Wznow");
            al_draw_text( font[BOLDS], color[2], 470, 430, ALLEGRO_ALIGN_CENTRE, "Poziom: ");
            al_draw_text( font[BOLDS], color[2], 540, 430, ALLEGRO_ALIGN_CENTRE, levelStr);
            al_draw_text( font[BOLDS], color[3], 470, 530, ALLEGRO_ALIGN_CENTRE, "Wyjscie");

			al_flip_display();
		}
		else if(draw)
        {
			
			al_clear_to_color(al_map_rgb(255,255,255));
			board->drawBoard();
			al_draw_rectangle(160+food->getX()+6, 60+food->getY()+6, 160+food->getX()+20-6, 60+food->getY()+20-6, al_map_rgb(0,0,0), 4);

			_itoa_s(result, resultStr, 5, 10);
		    al_draw_text( font[SMALL], al_map_rgb(128,128,128), 370, 10, ALLEGRO_ALIGN_CENTRE, "Wynik: ");
            al_draw_text( font[SMALL], al_map_rgb(128,128,128), 450, 10, ALLEGRO_ALIGN_CENTRE, resultStr);
            al_draw_text( font[SMALL], al_map_rgb(128,128,128), 640, 10, ALLEGRO_ALIGN_CENTRE, "Poziom: ");
            al_draw_text( font[SMALL], al_map_rgb(128,128,128), 720, 10, ALLEGRO_ALIGN_CENTRE, levelStr);
		    
			snake->drawSnake();

			al_flip_display();
			 
		}
		else if(endgame)
        {
			//al_clear_to_color(al_map_rgb(255,255,255));
            _itoa_s(result, resultStr, 5, 10);
            al_draw_filled_rectangle(160, 60, 1120, 660, al_map_rgba_f(0.7,0.7,0.7, 0.1));
            
            al_draw_text( font[BIG], al_map_rgb(128,128,128), 620, 250, ALLEGRO_ALIGN_CENTRE, "Koniec gry!");
            al_draw_text( font[BIG], al_map_rgb(128,128,128), 600, 350, ALLEGRO_ALIGN_CENTRE, "Wynik: ");
            al_draw_text( font[BIG], al_map_rgb(128,128,128), 770, 350, ALLEGRO_ALIGN_CENTRE, resultStr);
            al_flip_display();
			endgame = false;
        }
	}




}
/*
bool Game::operator== (Point& a)
{
	return ((snake->begin()->getX() == a.getX()) && (snake->begin()->getY() == a.getY()));
}


void Game::eaten()
{
	if(*this == *food)
	{
		std::cout << "\nFood: " << food->getX() << " " << food->getY() << "\nHead: " << snake->begin()->getX() << " " << snake->begin()->getY();
		food->updateFood();
		
	}
}*/
