#include "player.h"

#include <iostream>
#include <conio.h>


void player::movement()
{
	//Create multidimensional array
	const int NumRow = 5;
	const int NumColum = 5;

	//Map design
	char arr[NumRow][NumColum];
	std::fill((char*)arr, (char*)arr + NumRow * NumColum, '.');

	//Using @ for the player
	int row = 0, col = 0;
	arr[row][col] = '@';

	//Movement algoritm
	for (bool looping = true; looping;) {
		for (int r = 0; r < NumRow; r++) {
			std::cout << '\n';
			for (int c = 0; c < NumColum; c++) {
				std::cout << arr[r][c] << ' ';
				std::cout << ' ';
			}
		}
		std::cout << '\n';

		std::cout << "Use W for move Up\n";
		std::cout << "Use S for move Down\n";
		std::cout << "Use A for move Left\n";
		std::cout << "Use D for move Right\n";

		bool finish = true;
		int newcol = col, newrow = row;

		//Use _getch for manage the movement 
		switch (_getch()) {
		case 'w':
			--newrow;
			if (newrow == -1) {
				newrow++;
			}
			break;
		case 's':
			++newrow;
			if (newrow == 5) {
				newrow--;
			}
			break;
		case 'a':
			--newcol;
			if (newcol == -1) {
				newcol++;
			}
			break;
		case 'd':
			++newcol;
			if (newcol == 5) {
				newcol--;
			}
			break;
		default:
			finish = false;
		}

		if (finish && looping) {
			newrow = newrow < 0 ? newrow + NumRow : newrow % NumRow;
			newcol = newcol < 0 ? newcol + NumColum : newcol % NumColum;
			std::swap(arr[newrow][newcol], arr[row][col]);
			row = newrow;
			col = newcol;

		}
	}
}
