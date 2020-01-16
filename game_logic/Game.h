#ifndef _GAME
#define _GAME

#include <string>
#include "../warrior_class/Warrior.h"
#include "../map/Map.h"


class Game{

	Warrior &player1;
	Warrior &player2;
	Map map;

public:
	Game(Warrior &p1, Warrior &p2, Map _map);
	void start();


	
};


#endif
