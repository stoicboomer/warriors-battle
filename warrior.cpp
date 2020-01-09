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
		"DPT: " << _DPT << endl;
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

	if (target.onDefense){ //the defense stance reduces the damage taken
		
		target.onDefense = false;
		int dmg = _DPT * 0.4; 

		target._HP -= dmg;

		cout << target._nickname << " enters in a defensive stance!" << endl;
		cout << _nickname << " attacks " << target._nickname << " for " << dmg << "HP!" << endl;
		return dmg;
	}

	if (target.onParry){

		target.onParry = false;
	}

	cout << _nickname << " attacked " <<target._nickname << " for " << _DPT << "HP!" << endl;
	target._HP -= _DPT;

	return _DPT;
}

int Warrior::defense(){

	onDefense = true;
}

int Warrior::parry(){
	
	onParry = true;
}









