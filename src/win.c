#include "win.h"

GAMESCREEN* initGameScreen(){
	
	/*   1/5      3/5      1/5
		+----+-----------+----+
		| p1 |    log    | p2 |
		|    |           |    |
		|    +-----------+    |
		|    |    map    |    |
		|    |           |    |
		+----+-----------+----+
	*/

	int rows, cols;

	getmaxyx(stdscr, rows, cols);
	GAMESCREEN *screen = (GAMESCREEN*)malloc(sizeof(GAMESCREEN));	
	
	screen->leftP  = newwin((rows/5)*2, cols/5, 0, 0);
	screen->rightP = newwin((rows/5)*2, cols/5, 0, cols-(cols/5));

	screen->log = newwin((rows/5)*2, (cols/5)*3, 0, cols/5);
//	screen->map = newwin((rows/5)*3, (cols/5)*3, (rows/5)*2, cols/5);
	screen->map = newwin((rows/5)*3, cols, (rows/5)*2, 0);

	box(screen->leftP, 0, 0);
	box(screen->rightP, 0, 0);
	box(screen->log, 0, 0);
	box(screen->map, 0, 0);

	refresh();
	return screen;
}

void refreshScreen(GAMESCREEN *screen){

	wrefresh(screen->log);
	wrefresh(screen->map);
	wrefresh(screen->leftP);
	wrefresh(screen->rightP);
}

void deleteScreen(GAMESCREEN *screen){

	delwin(screen->log);
	delwin(screen->map);
	delwin(screen->leftP);
	delwin(screen->rightP);
	free(screen);
	erase();
}


//TODO 
void wrefreshWarrior(WINDOW *win, WARRIOR warrior){

	werase(win);
	box(win, 0, 0);

	char str[64];
	
	printwcenter(win, warrior.name, 2, 0); 
	sprintf(str, "HP: %d", warrior.hp);
	printwleft(win, str, 5, 0);
	sprintf(str, "DMG: %d", warrior.dmg);
	printwleft(win, str, 6, 0);
	sprintf(str, "STAMINA: %d", warrior.stamina);
	printwleft(win, str, 7, 0);
	
	if (warrior.isStunned && isExausted(warrior.stamina)){
		printwcenter(win, "STUNNED!", 10, BLACKYELLOW);
		printwcenter(win, "EXAUSTED!", 11, WHITERED);
	}	
	else if (warrior.isStunned){
		printwcenter(win, "STUNNED!", 10, BLACKYELLOW);
	}
	else if (isExausted(warrior.stamina)){
		printwcenter(win, "EXAUSTED!", 10, WHITERED);
	}
	
	if (warrior.isDefense){
		printwcenter(win, "DEFENSE!", 13, BLACKRED);
	}
	else if (warrior.isParry){
		printwcenter(win, "PARRY!", 13, BLACKGREEN);
	}

	#ifdef DEBUG
		
	sprintf(str, "ypos: %d", warrior.ypos);
	printwleft(win, str, 15, 0);
	sprintf(str, "xpos: %d", warrior.xpos);
	printwleft(win, str, 16, 0);

	#endif

	wrefresh(win);
} 


void printwcenter(WINDOW *win, const char *str, int row, int ATTR){

	wattron(win, COLOR_PAIR(ATTR));
	int cols = getmaxx(win);
	if (row == MIDDLE){
		int rows = getmaxy(win);
		mvwprintw(win, rows/1, (cols-strlen(str))/2, "%s", str); 
	}
	else{
		mvwprintw(win, row, (cols-strlen(str))/2, "%s", str); 
	}
	wattroff(win, COLOR_PAIR(ATTR));
}

void printwleft(WINDOW *win, const char *str, int row, int ATTR){
	
	wattron(win, COLOR_PAIR(ATTR));
	if (row == MIDDLE){
		int rows = getmaxy(win);
		mvwprintw(win, rows/2, 1, "%s", str); 
	}
	else{
		mvwprintw(win, row, 1, "%s", str);
	}
	wattroff(win, COLOR_PAIR(ATTR));
}

void printwright(WINDOW *win, const char *str, int row, int ATTR){
	
	wattron(win, COLOR_PAIR(ATTR));
	int cols = getmaxx(win);
	if (row == MIDDLE){
		int rows = getmaxy(win);
		mvwprintw(win, rows/2, cols-strlen(str)-1, "%s", str); 
	}
	else{
		mvwprintw(win, row, cols-strlen(str), "%s", str);
	}
	wattroff(win, COLOR_PAIR(ATTR));
}

int printAction(WINDOW *win, WARRIOR attacker, WARRIOR target, int ACTION_RESULT){
	
	int rows, cols;
	chtype tmp[2048];
	char buffer[2048];
	
	getmaxyx(win, rows, cols);

	switch (ACTION_RESULT){
		
		case A_ATTACK:
			sprintf(buffer, "%s attacked %s!", attacker.name, target.name);
			break;	

		case A_EXAUSTED:
			sprintf(buffer, "%s is exausted!", attacker.name);
			break;	

		case A_STUNNED:
			sprintf(buffer, "%s is stunned and his attack failed!", attacker.name, target.name);
			break;

		case A_FAIL_STUN:
			sprintf(buffer, "%s parry fails!", target.name, attacker.name);
			break;

		case A_SUCCESS_STUN:
			sprintf(buffer, "%s parry succedes on %s!", target.name, attacker.name);
			break;

		case A_OUT_OF_RANGE:
			sprintf(buffer, "%s attack failed! out of range!", attacker.name);
			break;
		
		case A_ATTACK_WHILE_STUNNED:
			sprintf(buffer, "%s manages to attack %s while stunned!", target.name, attacker.name);
			break;
		
		case A_ATTACK_ENEMY_DEFENSE:
			sprintf(buffer, "%s defenses from %s attack!", target.name, attacker.name);
			break;
		
		case A_DEFENSE_ON:
			sprintf(buffer, "%s enters in a defensive stance!", attacker.name);
			break;

		case A_PARRY_ON:
			sprintf(buffer, "%s prepares for a parry!", attacker.name);
			break;

		default:
			return 1;
	}	
	/*
		+------------------+
-->		|old actions       |  
|		|                  |   
|		+------------------+  
-->		|new action	       |
		+------------------+
	*/
	
	static int y = 1;
	if (y == rows-1){
		werase(win);
		box(win, 0, 0);
		y = 1;
	}
	mvwprintw(win, y, 1, buffer);
	y++;

/* TODO: SCROLL LOGS, 2HARD FOR MY SM4LL BRAIN (will add later, i think)

	mvwinchstr(win, rows-2, 1, tmp);
	for (int y = rows-3; y > 1; y--){
	
		//convert chtype to char
		for (chtype *ptr = tmp; *ptr != '\0'; ptr++){
			*ptr = *ptr & A_CHARTEXT;
		}

		while (1){
			
			wprintw(win, (char *)tmp);
			wrefresh(win);
			wmove(win, y, 1);
			wclrtoeol(win);

			//mvwprintw(win, y, 1, (char *)tmp);
		}
	}

	mvwprintw(win, rows-2, 1, buffer);	
*/
	
	wrefresh(win);
	return 0;
}

