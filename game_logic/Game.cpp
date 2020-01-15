#include "Game.h"


Game::Game(Warrior &p1, Warrior &p2)
	: player1(p1), 
	player2(p2)
//	map(_map)
{}

void Game::start(){

	int turn = 0;
	int action;

	while (player1.is_alive() && player2.is_alive()){	
		
		Warrior &player(turn % 2 == 0 ? player1 : player2);
		Warrior &opponent(turn % 2 == 0 ? player2 : player1);


		printf("+-----------------+-----------------+\n"
		       "  %s                  %s  	    \n"
		       "+-----------------+-----------------|\n"
		       "|		  |		    |\n"
		       "|HP:%d		  |HP:%d           |\n"
		       "|Stamina:%d      |Stamina:%d      |\n"
		       "|DMG:%d		  |DMG:%d           |\n"	
		       //"|		  |		    |\n"
		       "+-----------------------------------+\n",
		       player1._nickname.c_str(), player2._nickname.c_str(),
		       player1._HP, player2._HP,
		       player1.staminaBar, player2.staminaBar,
		       player1._DPT, player2._DPT);

	
CHOICE:
		cout << "(1 - attack | 2 - defense | 3 - parry)" << player._nickname << ":";
		cin  >> action;
		cout << endl << endl;

		switch(action){

			//actions
			case 1:
				player.attack(opponent);
				if (player.is_exausted() && (opponent.is_onDefense() || opponent.is_onParry())){
					opponent.addStamina(25);
				}
				break;
			case 2:
				player.defense();   //no attacks
				if (opponent.is_onDefense() || opponent.is_onParry()){
					opponent.addStamina(25);
				}
				break;
			case 3:
				player.parry();
				if (opponent.is_onDefense() || opponent.is_onParry()){ 
					opponent.addStamina(25);
				}
				break;
/*
			//movement
			case 'w' || 'W': //forward
				player.Y_pos -= 1;
				player.move(map, player.Y_pos, player.X_pos);
				break;

			case 's' || 'S': //back
				player.Y_pos += 1;
				player.move(map, player.Y_pos, player.X_pos);
				break;

			case 'a' || 'A': //left
				player.X_pos -= 1;
				player.move(map, player.Y_pos, player.X_pos);
				break;

			case 'd' || 'D': //right
				player.X_pos += 1;
				player.move(map, player.Y_pos, player.X_pos);
				break;
*/
			default:
				cout << "Invalid choice!" << endl;
				goto CHOICE;
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

