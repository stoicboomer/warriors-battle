#include "game_logic/Game.h"
#include "warrior_class/Warrior.h"

int main(){

	Warrior p1("Exodus", 50, 12);
	Warrior p2("Witcher", 56, 10);

	Game fight(p1, p2);
	fight.start();

	return 0;
}
