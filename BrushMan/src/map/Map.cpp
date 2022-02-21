#include "Map.h"

/// <summary>
/// Map constructor
/// </summary>
/// <param name="width">level width</param>
/// <param name="height">level height</param>
Map::Map(short width, short height)
{
	this->width = width;
	this->height = height;
	this->levelMap = nullptr;
	this->playerMap = nullptr;

	Init();
}

/// <summary>
/// Current level map print method
/// </summary>
void Map::Print()
{
	for (int i = 0; i < height; i++)
	{
		std::cout << " ";
		for (int j = 0; j < width; j++)
		{
			if (playerMap[i][j] != '@' && playerMap[i][j] != '~')
			{
				std::cout << levelMap[i][j];
			}
			else
			{
				std::cout << playerMap[i][j];
			}
			std::cout << " | ";
		}
		std::cout << "\n";
		std::cout << " ";
		for (int j = 0; j < width; j++)
		{
			std::cout << "- - ";
		}
		std::cout << "\n";
	}
}

/// <summary>
/// Get current player map
/// </summary>
/// <returns>saved playerMap</returns>
char** Map::GetPlayerMap()
{
	return playerMap;
}

/// <summary>
/// Get current level map
/// </summary>
/// <returns>saved levelMap</returns>
char** Map::GetLevelMap()
{
	return levelMap;
}

short Map::GetWidth()
{
	return this->width;
}

short Map::GetHeight()
{
	return this->height;
}

/// <summary>
/// Player map setter
/// </summary>
/// <param name="playerMap">new playerMap</param>
void Map::SetPlayerMap(char** playerMap)
{
	this->playerMap = playerMap;
}

/// <summary>
/// Calculate colored percentage
/// </summary>
/// <returns>percentage</returns>
void Map::CalculatePercent(float& percent)
{

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			if (playerMap[i][j] == '~') {
				percent++;
			}
		}
	}

	float z = width * height;
	percent = (percent / z);
}

/// <summary>
/// Maps initialization
/// </summary>
void Map::Init()
{
	if (levelMap != nullptr)
		return;

	levelMap = new char* [width];
	playerMap = new char* [width];
	for (int i = 0; i < height; i++)
	{
		levelMap[i] = new char[height];
		playerMap[i] = new char[height];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++) {
			levelMap[i][j] = ' ';
			playerMap[i][j] = ' ';
		}
	}

	playerMap[height-1][0] = '@';
}

/// <summary>
/// Maps destructor
/// </summary>
Map::~Map()
{
	for (int i = 0; i < width; ++i) {
		delete[] levelMap[i];
		delete[] playerMap[i];
	}
	delete[] levelMap;
	delete[] playerMap;
}