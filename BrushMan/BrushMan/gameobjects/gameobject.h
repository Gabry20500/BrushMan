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

		area = new char* [height];
		for (short i = 0; i < height; i++)
		{
			area[i] = new char[width];
		}

		for (int j = 0; j < height; j++)
		{
			std::cout << "\n";
			for (int i = 0; i < width; i++)
			{
				area[j][i] = 32;
				std::cout << "|" << area[j][i] << "|";
			}
		}
	}

	~GameObject()
	{
		for (short i = 0; i < height; i++)
		{
			delete[] area[i];
		}
	}

	bool is_overlapping(GameObject go) { return get_area() == go.get_area(); }
	//void onOverlap() = 0;

private:
	char** area = nullptr;
	unsigned short height = 0;
	unsigned short width = 0;
	char _symbol;

	unsigned short get_area() { return height * width; }
};

int main() {

	GameObject go(ObjectSymbol::PLAYER, 2, 4);


	system("pause");
	return 0;
}

