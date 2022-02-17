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
	
	currPos[yPos][xPos] = _symbol;
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

/// <summary>
/// move the gameobject horizontally by a given direction
/// </summary>
/// <param name="direction"></param>
void GameObject::move_lr(MoveDirection& direction)
{
	switch (direction)
	{
	case MoveDirection::UP:
		if (xPos < width - 1)
		{
			currPos[yPos][xPos] = static_cast<char>(ObjectSymbol::EMPTY);
			xPos += static_cast<int>(direction);
			currPos[yPos][xPos] = _symbol;
		}
		else direction = MoveDirection::DOWN;
		break;
	case MoveDirection::DOWN:
		if (xPos > 0)
		{
			currPos[yPos][xPos] = static_cast<char>(ObjectSymbol::EMPTY);
			xPos += static_cast<int>(direction);
			currPos[yPos][xPos] = _symbol;
		}
		else direction = MoveDirection::UP;
		break;
	default:
		break;
	}
}

/// <summary>
/// move the gameobject vertically by a given direction
/// </summary>
/// <param name="direction"></param>
void GameObject::move_ud(MoveDirection& direction)
{
	switch (direction)
	{
	case MoveDirection::UP:
		if (yPos < width - 1)
		{
			currPos[yPos][xPos] = static_cast<char>(ObjectSymbol::EMPTY);
			yPos += static_cast<int>(direction);
			currPos[yPos][xPos] = _symbol;
		}
		else direction = MoveDirection::DOWN;
		break;
	case MoveDirection::DOWN:
		if (yPos > 0)
		{
			currPos[yPos][xPos] = static_cast<char>(ObjectSymbol::EMPTY);
			yPos += static_cast<int>(direction);
			currPos[yPos][xPos] = _symbol;
		}
		else direction = MoveDirection::UP;
		break;
	default:
		break;
	}
}