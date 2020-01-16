#include "game_logic/Game.h"
#include "warrior_class/Warrior.h"

int main(){

	//create warrior objects
	Warrior p1("Exodus", 100, 10, 'E');
	Warrior p2("Witcher", 100, 10, 'W');

	//create fight map
	Map arena(6, 5);
	arena.fill('*');

	//start game
	Game game(p1, p2, arena);
	game.start();


	return 0;
}
