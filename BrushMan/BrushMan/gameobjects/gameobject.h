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

		area = new int* [height];
		for (short i = 0; i < height; i++)
		{
			area[i] = new int[width];
		}
	}

	bool is_overlapping(GameObject go) { return get_area() == go.get_area(); }

	virtual void onOverlap() = 0;
private:
	int** area = nullptr;
	unsigned short height = 0;
	unsigned short width = 0;
	char _symbol;

	unsigned short get_area() { return height * width; }
};