#ifndef _WARRIOR_COLORS_
#define _WARRIOR_COLORS_

#include <ncurses.h>

enum COLORS {

	//foreground 
	REDBLACK = 1,
	GREENBLACK,
	BLUEBLACK,
	YELLOWBLACK,

	//background
	WHITERED,
	WHITEBLUE,
	BLACKRED,
	BLACKYELLOW,
	BLACKWHITE,
	BLACKGREEN,
	BLACKBLACK,
	WHITEBLACK
};

int initGameColors();

#endif // _WARRIOR_COLORS_
