#include "win.h"
#include "colors.h"
#include "config.h"

#include <pthread.h>

int main(void){

	initscr();	
	keypad(stdscr, true);
	curs_set(0);
	noecho();
	
	GAMESCREEN *screen = initGameScreen();
	initGameColors();

	int maprows, mapcols, ch, r = 0, turns = 1;
	getmaxyx(screen->map, maprows, mapcols);

	WARRIOR p1 = {P1_NAME, P1_HP, P1_DMG, P1_STM, P1_STM, maprows/2, mapcols/2+10, 0, 0, false, false, false, 1};
	WARRIOR p2 = {P2_NAME, P2_HP, P2_DMG, P2_STM, P2_STM, maprows/2, mapcols/2-10, 0, 0, false, false, false, 2};

	refreshScreen(screen);

	movew(screen->map, &p1, 0);
	movew(screen->map, &p2, 0);
	wrefreshWarrior(screen->leftP, p1);
	wrefreshWarrior(screen->rightP, p2);
	wrefresh(screen->map);

	while (ch != KEY_F(1) && isAlive(p1.hp) && isAlive(p2.hp)){
		
		WARRIOR *attacker = turns % 2 == 0 ? &p1 : &p2;
		WARRIOR *target = turns % 2 == 0 ? &p2 : &p1;
		turns++;

		ch = getch();

		switch (ch){

			case '1':
			case '8':
				r = attackw(attacker, target);
				break;
			case '2':
			case '9':
				r = defense(attacker);
				break;
			case '3':
			case '0':
				r = parry(attacker);
				break;
			case 'w':
			case 'i':
				r = movew(screen->map, attacker, MOVE_UP);
				break;
			case 's':
			case 'k':
				r = movew(screen->map, attacker, MOVE_DOWN);
				break;
			case 'a':
			case 'j':
				r = movew(screen->map, attacker, MOVE_LEFT);
				break;
			case 'd':
			case 'l':
				r = movew(screen->map, attacker, MOVE_RIGHT);
				break;
			default:
				break;
		}
		//record action in the log window		
		if (r){
			printAction(screen->log, *attacker, *target, r);	
		}

		wrefreshWarrior(screen->leftP, p1);
		wrefreshWarrior(screen->rightP, p2);
		wrefresh(screen->map);
	}

	refresh();
	deleteScreen(screen);
	endwin();
	return 0;
}


