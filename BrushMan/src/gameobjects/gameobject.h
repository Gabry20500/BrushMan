#pragma once
#include <iostream>
#include "../map/Map.h"

/// <summary>
/// Gameobject's symbol on screen
/// </summary>
enum class ObjectSymbol : char
{
	EMPTY = 32,
	OBJECT = 'x',
	WALL = '/',
	SNOWFLAKE = '#',
	BOMB = 'O',
	HEARTH = '$'
};

/// <summary>
/// int to sum on movement direction
/// </summary>
enum class MoveDirection : int
{
	UP = 1,
	DOWN = -1
};

/// <summary>
/// Base class for the gameobjects in game
/// </summary>
class GameObject
{
public:
	GameObject(ObjectSymbol type, unsigned short height, unsigned short width)
	{
		/*_symbol = static_cast<char>(type);
		this->y = y;
		this->x = x;


		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
			{
				level.GetLevelMap()[j][i] = static_cast<char>(ObjectSymbol::EMPTY);
			}
		}*/

		
		symbol = static_cast<char>(type);
		this->height = height;
		this->width = width;
		//currPos = new char* [height];
		//for (short i = 0; i < height; i++) { currPos[i] = new char[width];
		//}
		//for (int j = 0; j < height; j++)
		//{
		//	for (int i = 0; i < width; i++)
		//	{ 
		//		currPos[j][i] = static_cast<char>(ObjectSymbol::EMPTY);
		//	}
		//}
	}

	~GameObject()
	{
	}

	void draw();
	void move_lr(MoveDirection& direction, Map& levelMap);
	void move_ud(MoveDirection& direction, Map& levelMap);
	virtual char on_overlap() { std::cout << "im gameobject\n"; return symbol; };

	void set_start_position(unsigned short x, unsigned short y);


protected:
	char** currPos = nullptr;
	unsigned short height = 0, width = 0, xPos = 0, yPos = 0;;
	char symbol;

	unsigned short get_area() { return height * width; }
};

class Obstacle : public GameObject
{
public:
	using GameObject::GameObject;
	virtual char on_overlap() override { std::cout << "im obstacle\n"; return symbol; };
};

class PowerUp : public GameObject
{
public:
	using GameObject::GameObject;
	virtual char on_overlap() override { std::cout << "im powerup\n"; return symbol; };
};
