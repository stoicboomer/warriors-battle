//warrior constructors/method functions!
#include "Warrior.h"

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


	cout << "---------------------" << endl <<
		"Name: " << _nickname << endl <<
		"HP: " << _HP << endl <<
		"DPT: " << _DPT << endl <<
		"Stamina: " << staminaBar << endl << 
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

bool Warrior::is_exausted(){

	if (staminaBar < 25){
		return true;
	}
	else{
		return false;
	}

}

bool Warrior::is_onDefense() { return onDefense; }
bool Warrior::is_onParry()   { return onParry;   }
bool Warrior::is_onStun()   { return onStun;    }

int Warrior::addStamina(int value){

	this -> staminaBar += value;

	if (staminaBar > staminaMax){
		staminaBar = staminaMax;
	}

	if (staminaBar < 0){
		staminaBar = 0;
	}


}


//warrior actions function methods

int Warrior::attack(Warrior &target){

	srand(time(NULL));

	//attacking changes your stance!
	onDefense = false;
	onParry	  = false;

	if (this -> is_onStun() && !this -> is_exausted()){

		if ( (rand() % 10) == 1){ // chance of ignoring stun is 10%
			
			int dmg = _DPT * 0.2;
			cout << _nickname << " manages to attack while stunned " << target._nickname <<
				" for " << dmg << "HP!" << endl;
			
			this -> addStamina(-25);
			target._HP -= dmg;
			return _DPT;
		}
		else{

			cout << _nickname << " is stunned and can't attack!" << endl;
			this -> addStamina(25);
			return 0;
		}

	}

	if (target.onDefense && !this -> is_exausted()){ //the defense stance reduces the damage taken
		
		target.onDefense = false;
		int dmg = _DPT * 0.4; 

		cout << _nickname << " attacks " << target._nickname << " for " << dmg << "HP!" << endl;
		this -> addStamina(-25);
		target.addStamina(25);
		target._HP -= dmg;

		return dmg;
	}
	if (target.is_onParry() && !this -> is_exausted()){

		target.onParry = false;

		if ( (rand() % 10) <= 5 ){ //chance of parry is 50%

			cout << _nickname << " attack gets parried and he's now stunned!" << endl;
			this -> onStun = true; //the attacker gets stunned

			this -> addStamina(-25);
			target.addStamina(25);

			return 0;
		}
		else{
			
			cout << target._nickname << " parry fails and " << _nickname << " attacks him for " << _DPT << "HP!" << endl;

			this -> addStamina(-25);
			target.addStamina(25);
			target._HP -= _DPT;	

			return _DPT;
		}
	}
	//direct attack
	if(staminaBar >= 25){

		cout << _nickname << " attacks " << target._nickname << " for " << _DPT << "HP!" << endl;
		this -> addStamina(-25);
		target._HP -= _DPT;
	}

	else{

		cout << _nickname << " is exausted!" << endl;
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


//player movement
void Warrior::move(Map &map, int y_pos, int x_pos){

	//old position of player(y  x) gets resetted
	static int current[2] = {0, 0};
	map.set(current[0], current[1], map.padding);	

	//new position
	map.set(y_pos, x_pos, 'A');
	
	cout << _nickname << " moves to " << y_pos << ":" << x_pos << endl;
	current[0] = y_pos;
	current[1] = x_pos;
}







