#include <stdio.h>


#define SIZE_WIDTH 5 
#define SIZE_HEIGHT 7 


struct Player{
	
	char simbol;
	int x;
	int y;

};


void fill(char map[][SIZE_WIDTH]){

	for (int i = 0; i < SIZE_HEIGHT; i++){
		for(int j = 0; j < SIZE_WIDTH; j++){

			map[i][j] = '*';

		}
	}


}

void printMap(char map[][SIZE_WIDTH]){


	for (int i = 0; i < SIZE_WIDTH; i++){

		printf("%s%d", i == 0 ? "   " : "  ", i);
	}

	puts("");

	for (int i = 0; i < SIZE_HEIGHT; i++){

		printf("%d", i);

		for(int j = 0; j < SIZE_WIDTH; j++){


			printf("  %c", map[i][j]);	

		}
		puts("");
	}

	puts("");

}


int main(void){

	char map[SIZE_HEIGHT][SIZE_WIDTH];

	fill(map);
	
	struct Player alex(3, 2, 'A');

	
	printMap(map);	



}
