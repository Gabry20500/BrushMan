#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> 

#include "player.h"
#include "gameloop.h"


void GameLoop()
{
	//Initializing first time loop bool
	bool first = true;
	//Inizializing time_t variable to store seconds between enemy movement
	time_t lastTime;
	time_t actualTime;
	time(&actualTime); //Getting actual time and inserting it in actualTime
	lastTime = actualTime; //Setting the moment of the last movement


	Player player;


	while (true)
	{
		char c = 'n';
		time(&actualTime);

		if (actualTime >= lastTime + 3 || first || _kbhit()) //If the enemy are ready to move or is the first loop or the player press a char
		{
			system("cls");
			if (actualTime >= lastTime + 3 || first) //First and second case, here enemies will move
			{
				lastTime = actualTime;
				first = false;
			}

			if (char command = _kbhit()) //input player found
			{
				command = _getch();
				player.Movement(command);
			}

			Sleep(100);
			player.PrintMap();
			
		}
	}
}