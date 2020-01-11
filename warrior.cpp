//warrior constructors/method functions!

#include "warrior.h"

//Warrior constructors
Warrior :: Warrior(){

	_nickname = " ";
	_HP  = 0;
	_DPT = 0;
}

Warrior :: Warrior(int HP, int DPT){

	_nickname = " ";
	_HP  = HP;
	_DPT = DPT;
}

Warrior :: Warrior(string nickname, int HP, int DPT){

	_nickname = nickname;
	_HP  = HP;
	_DPT = DPT;
}

//Warrior profile info functions

void Warrior::stats(){

	cout << "--- Warrior stats ---" << endl <<
		"Name: " << _nickname << endl <<
		"HP: " << _HP << endl <<
		"DPT: " << _DPT << endl <<
		"---------------------" << endl;
}

bool Warrior::is_alive(){

	if (_HP <= 0){
		return false;
	}

	else{
		return true;
	}
}

bool Warrior::is_onDefense() { return onDefense; }
bool Warrior::is_stunned() { return onStun; }

//warrior actions function methods

int Warrior::attack(Warrior &target){

	srand(time(NULL));

	if (this -> onStun){

		if ( (rand() % 10) == 1){ // chance of ignoring stun is 10%
			
			int dmg = _DPT * 0.7;
			cout << _nickname << " manages to attack while stunned " << target._nickname <<
				" for " << dmg << "HP!" << endl;
			
			target._HP -= dmg;
			return _DPT;
		}

		else{

			cout << _nickname << " is stunned and can't attack!" << endl;
			return 0;
		}

	}

	if (target.onDefense){ //the defense stance reduces the damage taken
		
		target.onDefense = false;
		int dmg = _DPT * 0.4; 

		target._HP -= dmg;

		cout << _nickname << " attacks " << target._nickname << " for " << dmg << "HP!" << endl;
		return dmg;
	}

	if (target.onParry){

		target.onParry = false;

		if ( (rand() % 10) <= 5 ){ //chance of parry is 50%

			cout << _nickname << " attack gets parried and he's now stunned!" << endl;
			this -> onStun = true; //the attacker gets stunned

			return 0;
		}

		else{
			
			cout << target._nickname << " parry fails and " << _nickname << " attacks him for " <<
				_DPT << "HP!" << endl;

			return _DPT;

		}
	}
	
	//direct attack
	else{

		cout << _nickname << " attacks " << target._nickname << " for " << _DPT << "HP!" << endl;

	}

}

int Warrior::defense(){

	cout << _nickname << " enters in a defensive stance!" << endl;
	onDefense = true;
}

int Warrior::parry(){
	
	cout << _nickname << " prepares for a parry!" << endl;
	onParry = true;
}









