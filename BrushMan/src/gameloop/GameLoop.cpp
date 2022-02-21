#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#include "gameloop.h"


#include "../map/Map.h"
#include "../player/player.h"
#include "../gameobjects/gameobject.h"


bool GameLoop(short width, short height, short level)
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

	float perc = 0.0f;

	//List of all entities in all levels
	Obstacle bomb1(ObjectSymbol::BOMB, 3, 3);
	MoveDirection dirBomb1 = MoveDirection::DOWN;

	PowerUp heart(ObjectSymbol::HEARTH, 0, 0);

	Obstacle snowF1(ObjectSymbol::SNOWFLAKE, 3, 2);
	MoveDirection dirSnowF1 = MoveDirection::DOWN;

	Obstacle snowF2(ObjectSymbol::SNOWFLAKE, 3, 4);
	MoveDirection dirSnowF2 = MoveDirection::UP;

	Obstacle wall(ObjectSymbol::WALL, 1, 6);
	MoveDirection dirWall = MoveDirection::DOWN;

	Obstacle bomb2(ObjectSymbol::BOMB, 2, 0);
	MoveDirection dirBomb2 = MoveDirection::UP;

	Obstacle bomb3(ObjectSymbol::BOMB, 5, 6);
	MoveDirection dirBomb3 = MoveDirection::DOWN;


	map.Print();
	//Switch on current level int
	switch (level)
	{
	case 1:
		while (true)
		{
			char c = 'n';
			time(&actualTime);
			if (actualTime >= lastTime + 2 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 2 || first) //First and second case, here enemies will move
				{
					lastTime = actualTime; //Setting new LastTime value
					first = false;
					system("cls");
					map.Print();
				}

				if (_kbhit()) //input player found
				{
					char input = tolower(_getch()); //Get Input
					player.movement(map, input);
					system("cls");
					map.Print();
					map.CalculatePercent(perc);

					if (perc >= 0.98f) {
						return true;
					}
				}
				std::cout << "Current Percentage: " << round(perc * 100) << "\n";
				std::cout << "Current health: " << player.getHealth() << "\n";
			}
		}
		break;
	case 2:
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 2 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 2 || first) //First and second case, here enemies will move
				{
					bomb1.move_lr(dirBomb1, map);
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
					map.CalculatePercent(perc);
					
					if (perc >= 0.98f) {
						return true;
					}
				}
				std::cout << "Current Percentage: " << round(perc * 100) << "\n";
				std::cout <<"Current health: " << player.getHealth()<< "\n";
			}
		}
		break;
	case 3:
		heart.spawnHeart(map);	//Spawning Heart Obj
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 2 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 2 || first) //First and second case, here enemies will move
				{
					bomb1.move_lr(dirBomb1, map);
					lastTime = actualTime;				//Moving Obstacles in the map
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
					map.CalculatePercent(perc);

					if (perc >= 0.98f) {
						return true;
					}
				}
				std::cout << "Current Percentage: " << round(perc * 100) << "\n";
				std::cout << "Current health: " << player.getHealth() << "\n";
			}
		}
		break;
	case 4:
		heart.spawnHeart(map);
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 2 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 2 || first) //First and second case, here enemies will move
				{
					snowF1.move_ud(dirSnowF1, map);
					snowF2.move_ud(dirSnowF2, map);
					bomb1.move_lr(dirBomb1, map);


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
					map.CalculatePercent(perc);

					if (perc >= 0.78f) {
						return true;
					}
				}
				std::cout << "Current Percentage: " << round(perc * 100) << "\n";
				std::cout << "Current health: " << player.getHealth() << "\n";
			}
		}
		break;
	case 5:
		heart.spawnHeart(map);
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 2 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 2 || first) //First and second case, here enemies will move
				{
					snowF1.move_ud(dirSnowF1, map);
					snowF2.move_ud(dirSnowF2, map);
					wall.move_lr(dirWall, map);
					bomb1.move_lr(dirBomb1, map);


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
					map.CalculatePercent(perc);

					if (perc >= 0.78f) {
						return true;
					}
				}
				std::cout << "Current Percentage: " << round(perc * 100) << "\n";
				std::cout << "Current health: " << player.getHealth() << "\n";
			}
		}
		break;
	case 6:
		heart.spawnHeart(map);
		while (true)
		{
			char c = 'n';
			time(&actualTime);

			if (actualTime >= lastTime + 2 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
			{
				if (actualTime >= lastTime + 2 || first) //First and second case, here enemies will move
				{
					snowF1.move_ud(dirSnowF1, map);		//Hyerarchy of movement of obstacles
					snowF2.move_ud(dirSnowF2, map);
					wall.move_lr(dirWall, map);
					bomb1.move_lr(dirBomb1, map);
					bomb2.move_lr(dirBomb2, map);
					bomb3.move_lr(dirBomb3, map);


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
					map.CalculatePercent(perc);

					if (perc >= 0.88f) {
						return true;
					}
				}
				std::cout << "Current Percentage: " << round(perc * 100) << "\n";
				std::cout << "Current health: " << player.getHealth() << "\n";
			}
		}
		break;
	}
}