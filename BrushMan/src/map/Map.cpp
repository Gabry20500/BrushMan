#include "Map.h"

Map::Map(short width, short height)
{
	this->width = width;
	this->height = height;
	this->levelMap = nullptr;
	this->playerMap = nullptr;

	Init();
}

void Map::Print()
{
	for (int i = 0; i < height; i++)
	{
		std::cout << " ";
		for (int j = 0; j < width; j++)
		{
			if (playerMap[i][j] != '@')
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

char** Map::GetPlayerMap()
{
	return playerMap;
}

void Map::SetPlayerMap(char** playerMap)
{
	this->playerMap = playerMap;
}

short Map::GetWidth()
{
	return this->width;
}

short Map::GetHeight()
{
	return this->height;
}

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

	playerMap[height-1][0] = '@';
}