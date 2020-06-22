#ifndef _WARRIOR_
#define _WARRIOR_

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <curses.h>

#include "config.h"

//macro functions
#define isExausted(stam) ((stam) <= 0 ? (true) : (false))
#define isAlive(hp)      ((hp)   >= 0 ? (true) : (false))

typedef struct _warrior{

	const char *name;
	int hp;
	int dmg;
	int stamina;
	const int staminamax;

	int ypos;
	int xpos;
	int oldypos;
	int oldxpos;

	bool isStunned;
	bool isDefense;
	bool isParry;
	
	const int playerid; //1 or 2 (left or right)

} WARRIOR;

//TBH i don't know when should i use unions or defines, i guess i'll learn by making mistakes
enum ACTION_RESULTS {
	
	A_ATTACK = 1,
	A_EXAUSTED, 
	A_STUNNED,
	A_FAIL_STUN,
	A_SUCCESS_STUN,
	A_OUT_OF_RANGE,
	A_ATTACK_WHILE_STUNNED,
	A_ATTACK_ENEMY_DEFENSE,
	A_DEFENSE_ON,
	A_PARRY_ON,
};

#define MOVE_UP 20
#define MOVE_DOWN 21
#define MOVE_LEFT 22
#define MOVE_RIGHT 23

//movement errors
#define MOVE_INVALID -1
#define MOVE_OUT_MAP -2 	
#define MOVE_COLLISION -3 //tries to move on another warrior position (body collision xd)

//logical
bool isOnRange(WARRIOR attacker, WARRIOR target);
bool isCollision(WINDOW *win, int y, int x); //check if in window yxpos there is something

//warrior actions
int attackw(WARRIOR *attacker, WARRIOR *target);		
int movew(WINDOW *win, WARRIOR *warrior, int MOVE);     
int defense(WARRIOR *warrior);							
int parry(WARRIOR *warrior);

#endif // _WARRIOR_
