//base warrior class

#ifndef _warrior_
#define _warrior_

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

class Warrior{

protected:
	//base stats
	string _nickname; 
	int    _HP; 
	int    _DPT; 
	
	//special stats
	bool onDefense = false;
	bool onStun    = false;
	bool onParry   = false;


public:
	//constructors
	Warrior();
	Warrior(int HP, int DPT);
	Warrior(string nickname, int HP, int DPT);

	//profile info function methods
	void stats();
	bool is_alive();
	bool is_onDefense();
	bool is_stunned();
	
	//warrior actions function methods
	int attack(Warrior &target);	
	int defense();
	int parry();

};

/*
		BERSERK THE UNSTOPPABLE
This warrior is a tough one, he doesn't stop at anything!
Equipped with his greatsword he slash everything he sees!
The more damage he takes the more furious becomes!!
When he's under 40% of life he enters in his berserk mode,
the damage increases and every attack adds one stack on
the bleed meter.
*/

class Berserk : public Warrior{

	bool rage = false;	


};






#endif
