#include <iostream>
#include <string>

#define SIZE_HEIGHT 7
#define SIZE_WIDTH 5 

using namespace std;

void fill(string *map, int height, int width){ //fills every array slot with '*'

	for (int row = 0; row < height; row++){
		for (int column = 0; column < width; column++){

			map[row][column] = '*';
		}
	}
}

void print(string map[][SIZE_WIDTH]){

	for (int column = 0; column < SIZE_WIDTH; column++){
		printf("%s%d", column  == 0 ? "   " : "  ", column);
	}
	cout << endl;
	for (int row = 0; row < SIZE_HEIGHT; row++){

		cout << row;
		for (int column = 0; column < SIZE_WIDTH; column++){
		
			cout << "  " << map[row][column];
		}
		cout << endl;
	}

	cout << endl;
}




int main(void){


	string map[SIZE_HEIGHT][SIZE_WIDTH];
	
	string *mapPtr = &map
	
	fill(mapPtr, SIZE_HEIGHT, SIZE_WIDTH);
	map[3][2] = 'A';

	print(map);

	return 0;
}

