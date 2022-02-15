#include "gameobject.h"

/// <summary>
/// return true il its position is equals to another gameobject
/// </summary>
/// <param name="go">the other gameobject</param>
/// <returns></returns>
//bool GameObject::is_overlapping(GameObject go)
//{
//	return (this->currPos[yPos][xPos] == go.currPos[go.yPos][go.xPos]);
//}

/// <summary>
/// set X and Y coordinates and change the value in the currPos array
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void GameObject::set_start_position(unsigned short x, unsigned short y)
{
	xPos = x;
	yPos = y;
	
	currPos[xPos][yPos] = _symbol;
}

/// <summary>
/// Draw the gameobject position on screen
/// </summary>
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
