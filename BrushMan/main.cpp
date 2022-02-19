#include "src/map/Map.h"
#include "src/player/player.h"

int main()
{
	Map mp(10,10);
	Player ply;

	mp.Print();
	ply.movement(mp);

	return 0;
}