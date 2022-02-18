#include <iostream>

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
	HEARTH = '$',
	PLAYER = '@'
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
		_symbol = static_cast<char>(type);
		this->height = height;
		this->width = width;

		currPos = new char* [height];
		for (short i = 0; i < height; i++)
		{
			currPos[i] = new char[width];
		}

		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				currPos[j][i] = static_cast<char>(ObjectSymbol::EMPTY);
			}
		}
	}

	~GameObject()
	{
		for (short i = 0; i < height; i++)
		{
			delete[] currPos[i];
		}
	}

	//bool is_overlapping(GameObject go);
	void set_start_position(unsigned short x, unsigned short y);

	void draw();
	void move_lr(MoveDirection& direction);
	void move_ud(MoveDirection& direction);
	virtual char on_overlap() { std::cout << "im gameobject\n"; return _symbol; };


protected:
	char** currPos = nullptr;
	unsigned short height = 0, width = 0, xPos = 0, yPos = 0;;
	char _symbol;

	unsigned short get_area() { return height * width; }
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
