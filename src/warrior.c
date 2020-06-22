#include "warrior.h"

//use your sword! if attack succedes returns the damage otherwise returns an ATTACK_RESULT constant
int attackw(WARRIOR *attacker, WARRIOR *target){

	srand(time(NULL));
	int totalDMG;

	attacker->isParry = false;
	attacker->isDefense = false;

	if (isExausted(attacker->stamina)){   //is the attacker exausted?
		return A_EXAUSTED;
	}
    
	else if (attacker->isStunned){       //is the attacker stunned?

		if ((rand() % 10) > 5){			 //50% to evade stun
		 	attacker->isStunned = false;
			return A_STUNNED;
		}
		else{
			attacker->isStunned = false;
			target->hp -= attacker->dmg;
			attacker->stamina -= NORMAL_ATTACK_STM;
			return A_ATTACK_WHILE_STUNNED;
		}
	}
	else if (target->isDefense && isOnRange(*attacker, *target)){ //defense reduces the damage taken by 60%
		totalDMG = (attacker->dmg * 0.4);
		target->isDefense = false;
		target->hp -=totalDMG;
		attacker->stamina -= NORMAL_ATTACK_STM;
		return A_ATTACK_ENEMY_DEFENSE;
	}
	else if (target->isParry && isOnRange(*attacker, *target)){
		
		if ((rand() % 10) > 5){			 //50% to stun
			target->isParry = false;
		 	attacker->isStunned = false;
			target->hp -= attacker->dmg;
			return A_FAIL_STUN;
		}
		else{
			target->isParry = false;
			attacker->isStunned = true;
			return A_SUCCESS_STUN;
		}
	}
	else{   //normal attack
		if (isOnRange(*attacker, *target)){
			target->isStunned = false;
			target->hp -= attacker->dmg;
			attacker->stamina -= NORMAL_ATTACK_STM;
			return A_ATTACK;
		}
		else{
			attacker->stamina -= NORMAL_ATTACK_STM;
			return A_OUT_OF_RANGE;
		}
	}
}

bool isCollision(WINDOW *win, int y, int x){
	
	//extract char
	int ch = mvwinch(win, y, x) & A_CHARTEXT;

	if (ch == ' '){
		return false;
	}
	return true;
}

bool isOnRange(WARRIOR attacker, WARRIOR target){
	
	//y axis check
	if (target.ypos-1 == attacker.ypos && target.xpos == attacker.xpos ||target.ypos+1 == attacker.ypos && target.xpos == attacker.xpos)
		return true;

	//x axis check
	if (target.ypos == attacker.ypos && target.xpos-1 == attacker.xpos || target.ypos == attacker.ypos && target.xpos+1 == attacker.xpos)
		return true;

	//diagonal check
	//top left corner
	else if (attacker.ypos+1 == target.ypos && attacker.xpos-1 == target.xpos) return true;

	//top right corner
	else if (attacker.ypos+1 == target.ypos && attacker.xpos+1 == target.xpos) return true;

	//bottom left corner
	else if (attacker.ypos-1 == target.ypos && attacker.xpos-1 == target.xpos) return true;
	
	//bottom right corner
	else if (attacker.ypos-1 == target.ypos && attacker.xpos+1 == target.xpos) return true; 

	else { return false; }
}

int defense(WARRIOR *warrior){
	
	warrior->isParry = false;
	warrior->isDefense = true;
	if (warrior->stamina == warrior->staminamax){
		return A_DEFENSE_ON;
	}

	warrior->stamina += STAMINA_REGEN;
	return A_DEFENSE_ON;
}

int parry(WARRIOR *warrior){
	
	warrior->isDefense = false;
	warrior->isParry = true;

	if (warrior->stamina == warrior->staminamax){
		return A_PARRY_ON;
	}
	
	warrior->stamina += STAMINA_REGEN;
	return A_PARRY_ON;
}

int movew(WINDOW *win, WARRIOR *warrior, int MOVE){
	
	int rows, cols;
	getmaxyx(win, rows, cols);
	
	switch (MOVE){

		case MOVE_UP:
			if (warrior->ypos == 1){
				return MOVE_OUT_MAP;
			}
			else if (isCollision(win, warrior->ypos-1, warrior->xpos)){
				refresh();
				return MOVE_COLLISION;
			}
			warrior->oldypos = warrior->ypos;
			warrior->oldxpos = warrior->xpos;
			warrior->ypos--;
			break;

		case MOVE_DOWN:
			if (warrior->ypos == rows-2){
				return MOVE_OUT_MAP;
			}
			else if (isCollision(win, warrior->ypos+1, warrior->xpos)){
				return MOVE_COLLISION;
			}
			warrior->oldypos = warrior->ypos;
			warrior->oldxpos = warrior->xpos;
			warrior->ypos++;
			break;

		case MOVE_LEFT:
			if (warrior->xpos == 1){
				return MOVE_OUT_MAP;
			}
			else if (isCollision(win, warrior->ypos, warrior->xpos-1)){
				return MOVE_COLLISION;
			}
			warrior->oldypos = warrior->ypos;
			warrior->oldxpos = warrior->xpos;
			warrior->xpos--;
			break;

		case MOVE_RIGHT:
			if (warrior->xpos == cols-2){
				return MOVE_OUT_MAP;
			}
			else if (isCollision(win, warrior->ypos, warrior->xpos+1)){
				return MOVE_COLLISION;
			}
			warrior->oldypos = warrior->ypos;
			warrior->oldxpos = warrior->xpos;
			warrior->xpos++;
			break;

		case 0:
			//nothing
			break;

		default:
			return MOVE_INVALID;
	}
	wattron(win, COLOR_PAIR(BLACKBLACK));
	mvwprintw(win, warrior->oldypos, warrior->oldxpos, " ");
	wattroff(win, COLOR_PAIR(BLACKBLACK));

	if (warrior->playerid == 1){
		wattron(win, COLOR_PAIR(P1_COLOR));
		mvwprintw(win, warrior->ypos, warrior->xpos, P1_SYMBOL);
		attroff(COLOR_PAIR(P1_COLOR));

	}else{
		wattron(win, COLOR_PAIR(P2_COLOR));
		mvwprintw(win, warrior->ypos, warrior->xpos, P2_SYMBOL);
		attroff(COLOR_PAIR(P2_COLOR));
	}

	return 0;
}

