#include <iostream>
#include <string>
#include "Map.h"

int main(void){

	Map arena(8, 6);

	arena.fill('*');

	arena.print();

	arena.set(1,3, 'A');
	arena.print();

	return 0;
}
