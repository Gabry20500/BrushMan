#ifndef MAP_H
#define MAP_H

#include <iostream>

class Map
{
private:
	short width;
	short height;
	char** levelMap;
	char** playerMap;
	unsigned short PlayerPercent;

public:
	// Map constructor
	Map(short width, short height);

	// Current level map print method
	void Print();

	// Get current player map
	char** GetPlayerMap();
	// Get current level map
	char** GetLevelMap();
	short GetWidth();
	short GetHeight();

	// Player map setter
	void SetPlayerMap(char** playerMap);

	// Calculate colored percentage
	unsigned short CalculatePercent();

	~Map();

private:
	void Init();
};

#endif !MAP_H