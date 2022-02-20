#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#include "gameloop.h"


#include "../map/Map.h"
#include "../player/player.h"
#include "../gameobjects/gameobject.h"


void GameLoop(short width, short height, short level)
{
	//Initializing first time loop bool
	bool first = true;

	//Inizializing time_t variable to store seconds between enemy movement
	time_t lastTime;
	time_t actualTime;
	time(&actualTime); //Getting actual time and inserting it in actualTime
	lastTime = actualTime; //Setting the moment of the last movement

	Map map(width, height);
	Player player;

	map.Print();
	switch (level)
	{
	case 1:
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 3 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 3 || first) //First and second case, here enemies will move
				{
					lastTime = actualTime;
					first = false;
					system("cls");
					map.Print();
				}

				if (_kbhit()) //input player found
				{
					char input = tolower(_getch());
					player.movement(map, input);
					system("cls");
					map.Print();
				}
			}
		}
		break;
	case 2:
		Obstacle bomb(ObjectSymbol::BOMB,3,3);
		MoveDirection dir = MoveDirection::UP;
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 3 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 3 || first) //First and second case, here enemies will move
				{
					bomb.move_lr(dir, map);
					lastTime = actualTime;
					first = false;
					system("cls");
					map.Print();
				}

				if (_kbhit()) //input player found
				{
					char input = tolower(_getch());
					player.movement(map, input);
					system("cls");
					map.Print();
				}
			}
		}
		break;
	}
}