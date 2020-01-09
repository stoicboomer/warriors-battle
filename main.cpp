#include <iostream>
#include <string>
#include "warrior.h"

using namespace std;

int main(void){

	
	Warrior warrior1("Exodus", 120, 30);
	Warrior warrior2("Clasemon", 100, 20);

	Warrior sample("Immortal", 999999999, 0);

	warrior1.attack(warrior2);
	warrior2.attack(warrior2);
	warrior1.parry();
	warrior2.attack(warrior1);
	warrior1.defense();
	warrior2.attack(warrior1);
	warrior1.attack(warrior2);



	return 0;
}


