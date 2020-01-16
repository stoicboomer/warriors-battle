#include "Game.h"


Game::Game(Warrior &p1, Warrior &p2, Map _map)
	: player1(p1), 
	player2(p2),
	map(_map)
{}

void Game::start(){

	int turn = 0;
	char action;

		Warrior &player(turn % 2 == 0 ? player1 : player2);
		player.spawn(map, 3);

		Warrior &opponent(turn % 2 == 0 ? player2 : player1);
		opponent.spawn(map, 4);

	while (player1.is_alive() && player2.is_alive()){	

		Warrior &player(turn % 2 == 0 ? player1 : player2);
		Warrior &opponent(turn % 2 == 0 ? player2 : player1);
		
		char output[4096];


		map.print();
		cout << "[" << player1._nickname << "][" << player1.symbol << "]\t"
		     << "[" << player2._nickname << "][" << player2.symbol << "]" <<  endl 
		     << "HP:" << player1._HP << "\t\t"          << "HP:" << player2._HP << endl 
		     << "STAMINA:" << player1.staminaBar << "\t"<< "STAMINA:" << player2.staminaBar << endl 
		     << "DMG:" << player1._DPT << "\t\t"	<< "DMG:" << player2._DPT << endl;

	
CHOICE:
		cout << "(1 - attack  | 2 - defense | 3 - parry)" << endl
		     << "(     W-A-S-D keys to move player     )" << player._nickname << ":";
		cin >> action;
		for (int i = 0; i < 50; i++){
			cout << endl;
		}

		switch(action){

			//actions
			case '1':
				player.attack(opponent);
				break;
			case '2':
				player.defense();   //no attacks
				if (opponent.is_onDefense() || opponent.is_onParry()) opponent.addStamina(25);
				break;
			case '3':
				player.parry();
				if (opponent.is_onDefense() || opponent.is_onParry()) opponent.addStamina(25);
				break;

			//movement
			case 'w': //forward
				cout << "w";
				player.move(map, 'w');
				if (opponent.is_onDefense() || opponent.is_onParry()) opponent.addStamina(25);
				break;

			case 's': //back
				cout << "s";
				player.move(map, 's');
				if (opponent.is_onDefense() || opponent.is_onParry()) opponent.addStamina(25);
				break;

			case 'a': //left
				cout << "a";
				player.move(map, 'a');
				if (opponent.is_onDefense() || opponent.is_onParry()) opponent.addStamina(25);
				break;

			case 'd': //right
				cout << "d";
				player.move(map, 'd');
				if (opponent.is_onDefense() || opponent.is_onParry()) opponent.addStamina(25);
				break;

			default:
				cout << "invalid choice! -> " << action << endl;
				goto CHOICE;
		}

		cout << player.Y_pos << ":" << player.X_pos << endl;
		turn++;
	}

	if (player1.is_alive()){
		cout << "***** " << player1._nickname << " wins the fight!******" << turn << endl;
	}
	else{
		cout << "****** " << player2._nickname << " wins the fight!******" << turn  << endl;
	}

}

