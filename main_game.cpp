#include "game_logic/Game.h"
#include "warrior_class/Warrior.h"

int main(){

	Warrior p1("Exodus", 100, 12);
	Warrior p2("Witcher", 100, 10);

	Warrior bruh("test", 999999999, 0);

	
	Game game(p1, p2);

	game.start();


	return 0;
}
