#include "Game.h"


Game::Game(Warrior &p1, Warrior &p2)
	: player1(p1), 
	player2(p2)	
{}





void Game::start(){

	int turn = 0;
	int action;

	while (player1.is_alive() && player2.is_alive()){
		
		Warrior &player(turn % 2 == 0 ? player1 : player2);
		Warrior &opponent(turn % 2 == 0 ? player2 : player1);

		player1.stats();
		player2.stats();

		cout << "|--- Commands ---|" << endl <<
			"|  1 - Attack!   |" << endl <<
			"|  2 - Defense!  |" << endl <<
			"|  3 - Parry!    |" << endl <<
			"|----------------|" << endl;	

		cout << "[!!!] " << player._nickname << " turn!\nEnter a command:";
		cin  >> action;

		switch(action){

			case 1:
				player.attack(opponent);
				break;
			case 2:
				player.defense();
				break;
			case 3:
				player.parry();
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
		}

		turn++;
	}

	if (player1.is_alive()){
		cout << player1._nickname << " wins the fight!" << turn << endl;
	}
	else{
		cout << player2._nickname << " wins the fight!" << turn  << endl;
	}

	
}

