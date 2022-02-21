#pragma once
#include "../map/Map.h"

class Player {
public:
	void movement(Map& mapRef, char input);
	char** getPlayerPosition(Map& mapRef);

	unsigned short getHealth();
protected:
	unsigned short health = 3;
};