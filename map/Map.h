#ifndef _MAP
#define _MAP

#include <string>

using namespace std;

class Map{

protected:

	int height;
	int width;

	string *map;

public:
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
