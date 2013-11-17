#include "Game.h"
#include "Collision.h"
#include <iostream>



Game::Game(void)
{
	sizeX = 48;
	sizeY = 30;
	
	file = new FileMng;

	board = new Board(&currLevel, &result, &font);
	menuBoard= new Menu(&currLevel, &result, &font, file->tab);
	endBoard = new Endgame(&currLevel, &result, &font);

	
	snake = NULL;
	food = new Food(sizeX, sizeY, 20);
	//bigFood = new BigFood(sizeX,sizeY);
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
	file->save();
	delete board;
	if(snake) delete snake;
	delete food;
	//delete bigFood;
	delete menuBoard;
	delete file;
	delete endBoard;
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
	//bigFood->update();
	//bigFood->update();
	tmpDir = RIGHT;
	result = 0;
	menu = false;
	draw = true;
	endgame = false;
	
	
	
}


void Game::mainLoop()
{
	Object::adjPos(WindowWidth, WindowHeight);
	file->load();

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
							if(!endgame) draw = true;
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
					draw = false;
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
				file->update(result);
			}

            snake->dir = tmpDir;
			
			if(*food == *snake)
			{
				result += ((currLevel+1)*food->value);
				 BigFood::time++;
				int t=0;
				do
				{
					food->update();
					t++;
					if(t>1) std::cout << "WORKS!\n";
				} while(Collision::inSnake(*snake, *food));

				snake->growSnake();

			}

			if(BigFood::time >= 10 && !BigFood::active)
			{
				
				if(rand()%2==0)
					bigFood = new LongFood(sizeX,sizeY);
				else
					bigFood = new BigFood(sizeX,sizeY);
				printf("1. Food: (%d, %d)\tSnake: (%d, %d)\n", bigFood->getX(), bigFood->getY(), snake->head()->getX(), snake->head()->getY());
				abort = 0;
				while(Collision::inSnake(*snake, bigFood->elements) && abort < 10);
				{
					std::cout << "WORKS2!\n";
					
					bigFood->update();
					printf("2. Food: (%d, %d)\tSnake: (%d, %d)\n", bigFood->getX(), bigFood->getY(), snake->head()->getX(), snake->head()->getY());

					abort++;
				} 

				if(abort < 10) 	
				{
					BigFood::active = true;
					BigFood::time = 500;
				}
				else
					delete bigFood;
				
			}

			//printf("BigFood time: %d\n", BigFood::time);

			if(BigFood::active)
			{
				BigFood::time--;
				if(*bigFood == *snake)
				{
					result += ((currLevel+1)*bigFood->value);
					snake->growSnake();
					BigFood::time = 0;
					delete bigFood;
				}

				if(BigFood::time <= 0) BigFood::active = false;
			}


            if(draw) snake->update();
		}
		else if(events.type == ALLEGRO_EVENT_TIMER && menu)
			menuBoard->update();
		
		
		if(menu)
		{
			al_clear_to_color(al_map_rgb(255,255,255));
			menuBoard->draw();
			al_flip_display();
		}
		else if(draw)
        {
			al_clear_to_color(al_map_rgb(255,255,255));
			board->draw();
			food->draw();	
			if(BigFood::active)
				bigFood->draw();
			snake->draw();

			al_flip_display();
			 
		}
		else if(endgame)
        {
			al_clear_to_color(al_map_rgb(255,255,255));
			board->draw();
			food->draw();		    
			snake->draw();
			endBoard->draw();
        }
	}
}