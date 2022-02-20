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
	GameObject(ObjectSymbol type, Map& level, unsigned short y, unsigned short x)
	{
		_symbol = static_cast<char>(type);
		this->y = y;
		this->x = x;


		for (int j = 0; j < y; j++)
		{
			for (int i = 0; i < x; i++)
			{
				level.GetLevelMap()[j][i] = static_cast<char>(ObjectSymbol::EMPTY);
			}
		}
	}

	~GameObject()
	{
		for (short i = 0; i < y; i++)
		{
			delete[] currPos[i];
		}
	}

	void draw();
	void move_lr(MoveDirection& direction);
	void move_ud(MoveDirection& direction);
	virtual char on_overlap() { std::cout << "im gameobject\n"; return _symbol; };


protected:
	char** currPos = nullptr;
	unsigned short y = 0, x = 0, xPos = 0, yPos = 0;;
	char _symbol;

	unsigned short get_area() { return y * x; }
};

class Obstacle : public GameObject
{
public:
	using GameObject::GameObject;
	virtual char on_overlap() override { std::cout << "im obstacle\n"; return _symbol; };
};

class PowerUp : public GameObject
{
public:
	using GameObject::GameObject;
	virtual char on_overlap() override { std::cout << "im powerup\n"; return _symbol;	};
};
