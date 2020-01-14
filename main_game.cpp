#include "game_logic/Game.h"
#include "warrior_class/Warrior.h"

int main(){

	Warrior p1("Exodus", 50, 12);
	Warrior p2("Witcher", 56, 10);

	Map arena(5, 5);

	arena.fill('*');
	arena.print();

	int y, x;

	while (1){

		arena.print();

		cin >> y >> x;
		p1.move(arena, y, x);

	}



	return 0;
}
