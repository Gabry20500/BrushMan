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

	void Print();
	char** GetPlayerMap();
	void SetPlayerMap(char** playerMap);

	short GetWidth();
	short GetHeight();

private:
	void Init();
};

#endif // !MAP_H
