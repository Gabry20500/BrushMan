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
void GameObject::move_lr(MoveDirection& direction, Map& levelMap)
{
	//Create multidimensional array
	int NumRow = levelMap.GetHeight();
	int NumColum = levelMap.GetWidth();
	//Movement algoritm
	bool quit = false;

	char** enemyMap = new char* [NumRow];
	for (int i = 0; i < NumRow; i++) {
		enemyMap[i] = new char[NumColum];
	}

	enemyMap = levelMap.GetLevelMap();

	enemyMap[height][width] = symbol;

	switch (direction)
	{
	case MoveDirection::UP:
		if (width < NumColum - 1)
		{
			enemyMap[height][width] = static_cast<char>(ObjectSymbol::EMPTY);
			width += static_cast<int>(direction);
			enemyMap[height][width] = symbol;
		}
		else direction = MoveDirection::DOWN;
		break;
	case MoveDirection::DOWN:
		if (width > 0)
		{
			enemyMap[height][width] = static_cast<char>(ObjectSymbol::EMPTY);
			width += static_cast<int>(direction);
			enemyMap[height][width] = symbol;
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
void GameObject::move_ud(MoveDirection& direction, Map& levelMap)
{
	//Create multidimensional array
	int NumRow = levelMap.GetHeight();
	int NumColum = levelMap.GetWidth();
	//Movement algoritm
	bool quit = false;

	char** enemyMap = new char* [NumRow];
	for (int i = 0; i < NumRow; i++) {
		enemyMap[i] = new char[NumColum];
	}

	enemyMap = levelMap.GetLevelMap();

	enemyMap[height][width] = symbol;

	switch (direction)
	{
	case MoveDirection::UP:
		if (height < NumRow - 1)
		{
			enemyMap[height][width] = static_cast<char>(ObjectSymbol::EMPTY);
			height += static_cast<int>(direction);
			enemyMap[height][width] = symbol;
		}
		else direction = MoveDirection::DOWN;
		break;
	case MoveDirection::DOWN:
		if (height > 0)
		{
			enemyMap[height][width] = static_cast<char>(ObjectSymbol::EMPTY);
			height += static_cast<int>(direction);
			enemyMap[height][width] = symbol;
		}
		else direction = MoveDirection::UP;
		break;
	default:
		break;
	}
}


/// <summary>
/// set X and Y coordinates and change the value in the currPos array
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void GameObject::set_start_position(unsigned short x, unsigned short y)
{
	xPos = x;
	yPos = y;

	currPos[yPos][xPos] = symbol;
}
