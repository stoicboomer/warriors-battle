#include <iostream>
#include <string>
#include "Map.h"

int main(void){

	Map arena(10, 5);

	arena.fill('*');

	arena.print();


	return 0;
}
