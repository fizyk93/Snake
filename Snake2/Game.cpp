#include "Game.h"
#include <iostream>


Game::Game(void)
{
	sizeX = 48;
	sizeY = 30;
	board = new Board(&currLevel, &result, &font);
	menuBoard= new Menu(&currLevel, &result, &font);
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
	delete menuBoard;
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
	food->update();
	tmpDir = RIGHT;
	result = 0;
	menu = false;
	draw = true;
	Object::adjPos(WindowWidth, WindowHeight);
	
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
                    menuBoard->option = addModulo(--(menuBoard->option), 4);
                    break;
                case ALLEGRO_KEY_DOWN:
                     menuBoard->option = addModulo(++(menuBoard->option), 4);
                    break;
                case ALLEGRO_KEY_ENTER:
                    if(menuBoard->option == 0)
						resetGame();
					else if(menuBoard->option == 1)
                    {
						if(!snake) resetGame();
						else
						{
							draw = true;
							menu = false;
						}
                        
                    }
                    else if(menuBoard->option == 3)
                        done = true;
                    break;
				case ALLEGRO_KEY_RIGHT:
					if(menuBoard->option == 2)
					{
						currLevel = addModulo(++currLevel, 10);
						loadLevel(currLevel);
					}
					break;
				case ALLEGRO_KEY_LEFT:
					if(menuBoard->option == 2)
					{
						currLevel = addModulo(--currLevel, 10);
						loadLevel(currLevel);
					}
					break;
				case ALLEGRO_KEY_ESCAPE:
                    menuBoard->option = 3;
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
                    if(snake->dir == DOWN) break;
                    tmpDir = UP;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    if(snake->dir == LEFT) break;
                    tmpDir = RIGHT;
                    break;
                case ALLEGRO_KEY_DOWN:
                    if(snake->dir == UP) break;
                    tmpDir = DOWN;
                    break;
                case ALLEGRO_KEY_LEFT:
                    if(snake->dir == RIGHT) break;
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

            snake->dir = tmpDir;
			
			if(*food == *snake->head())
			{
				result += (currLevel+1);
				do
				{
				food->update();
				}while(snake->inSnake(*food));

				snake->growSnake();

			}


            if(draw) snake->update();
		}
		else if(events.type == ALLEGRO_EVENT_TIMER && menu)
			menuBoard->update();
		


		//al_clear_to_color(al_map_rgb(255,255,255));
		
		if(menu)
		{
			draw = false;
			menuBoard->draw();
			al_flip_display();
		}
		else if(draw)
        {
			
			al_clear_to_color(al_map_rgb(255,255,255));
			board->draw();
			food->draw();		    
			snake->draw();

			al_flip_display();
			 
		}
		else if(endgame)
        {
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
