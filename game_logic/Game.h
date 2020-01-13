#ifndef _GAME
#define _GAME

#include <string>
#include "../warrior_class/Warrior.h"


class Game{

	Warrior &player1;
	Warrior &player2;

public:
	Game(Warrior &p1, Warrior &p2);
	void start();


	
};


#endif
