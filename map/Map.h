#ifndef _MAP
#define _MAP

#include <string>

using namespace std;

class Map{

	string *map;
	
public:
	int height;
	int width;

	//constructor
	Map(int _height, int _width);

	//map modifiers
	char padding;
	void fill(char symbol);
	void set(int , int , char );

	//map visual
	void print();
	
};


#endif
