#include "Game.h"
#include <iostream>

int main(void){

	Warrior p1("Exodus", 500, 25);
	Warrior p2("emeriti", 500, 12);
	
	Game game(p1, p2);

	game.start();


	return 0;
}
