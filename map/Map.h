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

	//function methods
	void fill(char symbol);
	void print();
	
};


#endif
