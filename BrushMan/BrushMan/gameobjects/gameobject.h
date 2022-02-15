enum ObjectSymbol : char
{
	OBJECT = 'x',
	WALL = '/',
	SNOWFLAKE = '#',
	BOMB = 'O',
	HEARTH = '$',
	PLAYER = '@'
};

class GameObject
{
public:
	GameObject(char type, unsigned short height, unsigned short width) : _symbol(type), height(height), width(width) {}
	bool is_overlapping(GameObject go) { return get_area() == go.get_area(); }

	virtual void onOverlap() = 0;
private:
	unsigned short height = 0;
	unsigned short width = 0;
	const char _symbol;

	unsigned short get_area() { return height * width; }
};