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

Warrior :: Warrior(string nickname, int HP, int DPT, char s):

	_nickname(nickname),
	_HP(HP),
	_DPT(DPT),
	symbol(s)
{}

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

//check if attack is in range
bool Warrior::is_onRange(Warrior &target, int range){
	
	//y axis check
	if (target.Y_pos-1 == Y_pos && target.X_pos == X_pos || target.Y_pos+1 == Y_pos && target.X_pos == X_pos) 
		return true;

	//x axis check
	else if (target.X_pos-1 == X_pos && target.Y_pos == Y_pos || target.X_pos+1 == X_pos && target.Y_pos == Y_pos)
	       	return true;

	//diagonal check
	//top left corner
	else if (target.Y_pos+1 == Y_pos && target.X_pos+1 == X_pos) return true;

	//top right corner
	else if (target.Y_pos+1 == Y_pos && target.X_pos-1 == X_pos) return true;

	//bottom left corner
	else if (target.Y_pos-1 == Y_pos && target.X_pos+1 == X_pos) return true;
	
	//bottom right corner
	else if (target.Y_pos-1 == Y_pos && target.X_pos-1 == X_pos) return true;

	else{
		return false;
	}
	
}

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

	if (this -> is_onRange(target, 1)){

		if (this -> is_onStun() && !this -> is_exausted()){

			if ( (rand() % 10) == 1){ // chance of ignoring stun is 10%
				
				int dmg = _DPT * 0.2;
				cout << _nickname << " manages to attack while stunned " << target._nickname <<
					" for " << dmg << "HP!" << endl;
				
				this -> addStamina(-25);
				target._HP -= dmg;
				onStun = false;
				return _DPT;
			}
			else{

				cout << _nickname << " is stunned and can't attack!" << endl;
				this -> addStamina(25);
				onStun = false;
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
	
	else{

		cout << "Attack is out of range" << endl;
		this -> addStamina(-25);

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
int Warrior::move(Map &map, char direction){

	old_pos[0] = Y_pos;
	old_pos[1] = X_pos;
	switch(direction){

		case 'w':
			
			if (Y_pos == 0) break;
			else{
				Y_pos -= 1;
			}
			break;

		case 's':
			if (Y_pos == map.height-1) break;
			else{
				Y_pos += 1;
			}
			break;

		case 'a':
			if (X_pos == 0) break;
			else{
				X_pos -= 1;
			}
			break;

		case 'd':
			if (X_pos == map.width-1) break;
			else{
				X_pos += 1;
			}
			break;
	}

	//clear old pos
	map.set(old_pos[0], old_pos[1], map.padding);

	//add new pos
	map.set(Y_pos, X_pos, symbol);
	
}
/*
 * 1 -> Top left corner
 * 2 -> Top right corner
 * 3 -> Bottom left corner
 * 4 -> Bottom right corner
 */
int Warrior::spawn(Map &map, int corner){
	
	switch (corner){
	
		case 1:	
			Y_pos = 0;
			X_pos = 0;	
			map.set(Y_pos, X_pos, symbol);
			return 0;
		case 2:
			Y_pos = 0;
			X_pos = map.width-1;
			map.set(Y_pos, X_pos, symbol);
			return 0;
		case 3:
			Y_pos = map.height-1;
			X_pos = 0;
			map.set(Y_pos, X_pos, symbol);
			return 0;
		case 4:
			Y_pos = map.height-1;
			X_pos = map.width-1;
			map.set(Y_pos, X_pos, symbol);
			return 0;

		defaul:
			return 1;
	}
}







