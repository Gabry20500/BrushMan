#include <iostream>

/// <summary>
/// Gameobject's symbol on screen
/// </summary>
enum ObjectSymbol : char
{
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
enum MoveDirection : int
{
	UP = 1,
	DOWN = -1,
	RIGHT = 1,
	LEFT = -1
};

/// <summary>
/// Base class for the gameobjects in game
/// </summary>
class GameObject
{
public:
	GameObject(char type, unsigned short height, unsigned short width)
	{
		_symbol = type;
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
				currPos[j][i] = 32;
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
	virtual void onOverlap() { std::cout << "im gameobject\n"; };

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
	virtual void onOverlap() override { std::cout << "im obstacle\n"; };
};

class PowerUp : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void onOverlap() override { std::cout << "im powerup\n"; };
};

int main() {

	Obstacle obs(ObjectSymbol::BOMB, 4, 4);
	PowerUp pp(ObjectSymbol::HEARTH, 4, 4);

	obs.set_start_position(1, 3);
	pp.set_start_position(3, 2);
	obs.onOverlap();
	pp.onOverlap();

	obs.draw();

	system("pause");
	return 0;
}

