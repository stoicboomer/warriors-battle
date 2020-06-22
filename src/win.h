#ifndef _WARRIOR_WIN_
#define _WARRIOR_WIN_
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "warrior.h"
#include "colors.h"

#define MIDDLE -1

typedef struct _gamescreen{
	
	WINDOW *log;
	WINDOW *map;
	WINDOW *leftP;
	WINDOW *rightP;

} GAMESCREEN;

//SCREEN MANAGMENT
GAMESCREEN* initGameScreen();
void refreshScreen(GAMESCREEN *screen);
void deleteScreen(GAMESCREEN *screen);

//UTILITIES
void printwcenter(WINDOW *win, const char *str, int row, int ATTR);
void printwleft(WINDOW *win, const char *str, int row, int ATTR);
void printwright(WINDOW *win, const char *str, int row, int ATTR);

//WARRIOR STATS WINDOW MANAGMENT
void wrefreshWarrior(WINDOW *win, WARRIOR warrior);
int printAction(WINDOW *win, WARRIOR attacker, WARRIOR target, int ACTION_RESULT);

#endif // _WARRIOR_WIN_
