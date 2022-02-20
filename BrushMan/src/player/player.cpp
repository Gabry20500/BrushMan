#include "player.h"

#include <iostream>
#include <conio.h>


void Player::movement(Map& mapRef, char input)
{
	//Create multidimensional array
	int NumRow = mapRef.GetHeight();
	int NumColum = mapRef.GetWidth();

	int row = 0;
	int col = 0;

	char** mov = new char* [NumRow];
	for (int i = 0; i < NumRow; i++) {
		mov[i] = new char[NumColum];
	}

	mov = mapRef.GetPlayerMap();

	//Movement algoritm
	bool quit = false;

	//Use _getch for manage the movement 
	switch (input) {
	case 'w':
		for (int i = 0; i < NumRow && quit == false; i++)
		{
			for (int j = 0; j < NumColum && quit == false; j++)
			{
				if (i > 0)
				{
					if (mov[i][j] == '@')
					{
						mov[i][j] = '~';
						mov[i - 1][j] = '@';
						quit = true;
					}
				}
			}
		}
		break;
	case 's':
		for (int i = 0; i < NumRow && quit == false; i++)
		{
			for (int j = 0; j < NumColum && quit == false; j++)
			{
				if (i < NumRow - 1)
				{
					if (mov[i][j] == '@' && quit == false)
					{
						mov[i][j] = '~';
						mov[i + 1][j] = '@';
						quit = true;
					}
				}
			}
		}
		break;
	case 'a':
		for (int i = 0; i < NumRow && quit == false; i++)
		{
			for (int j = 0; j < NumColum && quit == false; j++)
			{
				if (j > 0)
				{
					if (mov[i][j] == '@' && quit == false)
					{
						mov[i][j] = '~';
						mov[i][j - 1] = '@';
						quit = true;
					}
				}
			}
		}
		break;
	case 'd':
		for (int i = 0; i < NumRow && quit == false; i++)
		{
			for (int j = 0; j < NumColum && quit == false; j++)
			{
				if (j < NumColum - 1)
				{
					if (mov[i][j] == '@' && quit == false)
					{
						mov[i][j] = '~';
						mov[i][j + 1] = '@';
						quit = true;
					}
				}
			}
		}
	break;
	}
}