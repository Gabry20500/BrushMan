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

public:
	// Map constructor
	Map(short width, short height);

	// Current level map print method
	void Print();

	// Map getters
	char** GetPlayerMap();
	short GetWidth();
	short GetHeight();

	// Player map setter
	void SetPlayerMap(char** playerMap);

	// Maps destructor
	~Map();

private:
	// Maps initialization
	void Init();
};

#endif // !MAP_H
