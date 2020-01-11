#include <iostream>
#include <string>
#include "warrior.h"

using namespace std;

int main(void){

	
	Warrior warrior1("Exodus", 120, 30);
	Warrior warrior2("Clasemon", 100, 20);

	Warrior sample("Immortal", 999999999, 0);

	Berserk Guts;

	cout <<	Guts.is_alive();


	return 0;
}


