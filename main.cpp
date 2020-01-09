#include <iostream>
#include <string>
#include "warrior.h"

using namespace std;

int main(void){


	Warrior warrior1("Exodus", 100, 20);
	Warrior warrior2("Clasemon", 300, 30);

	warrior1.stats();
	warrior1.defense();
	warrior2.attack(warrior1);
	warrior1.stats();



	return 0;
}


