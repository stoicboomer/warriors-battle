#include "colors.h"

int initGameColors(){

	//check if terminal supports colors
	if (has_colors() == FALSE){
		return 1;
	}
	start_color();

	//initialize different color attributes
	//foreground
	init_pair(REDBLACK, COLOR_RED, COLOR_BLACK);
	init_pair(GREENBLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(BLUEBLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(YELLOWBLACK, COLOR_YELLOW, COLOR_BLACK);
	//background
	init_pair(WHITERED, COLOR_WHITE, COLOR_RED);
	init_pair(WHITEBLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(BLACKRED, COLOR_BLACK, COLOR_RED);
	init_pair(BLACKYELLOW, COLOR_BLACK, COLOR_YELLOW);
	init_pair(BLACKGREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(BLACKWHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(BLACKBLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(WHITEBLACK, COLOR_WHITE, COLOR_BLACK);

	return 0;
}

