#include <iostream>

enum ObjectSymbol : char
{
	OBJECT = 'x',
	WALL = '/',
	SNOWFLAKE = '#',
	BOMB = 'O',
	HEARTH = '$',
	PLAYER = '@'
};

enum MoveDirection : int
{
	UP = 1,
	DOWN = -1,
	RIGHT = 1,
	LEFT = -1
};

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


		set_start_position(1, 2);
	}

	~GameObject()
	{
		for (short i = 0; i < height; i++)
		{
			delete[] currPos[i];
		}
	}

	bool is_overlapping(GameObject go) { return get_area() == go.get_area(); }
	void set_start_position(unsigned short x, unsigned short y);
	void draw();
	//void onOverlap() = 0;

private:
	char** currPos = nullptr;
	//char** currPos = nullptr;
	unsigned short height = 0, width = 0, xPos = 0, yPos = 0;;
	char _symbol;

	unsigned short get_area() { return height * width; }
};

int main() {

	GameObject go(ObjectSymbol::PLAYER, 4, 4);
	go.draw();

	system("pause");
	return 0;
}

