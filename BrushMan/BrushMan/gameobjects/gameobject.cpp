#include "gameobject.h"

void GameObject::set_start_position(unsigned short x, unsigned short y)
{
	xPos = x;
	yPos = y;
	
	currPos[xPos][yPos] = _symbol;
}

void GameObject::draw()
{
	for (int j = 0; j < height; j++)
	{
		std::cout << "\n";
		for (int i = 0; i < width; i++)
		{
			std::cout << "|" << currPos[j][i] << "|";
		}
	}
}
