#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class foo{

	int x, y;
	string *asd;

public:
	foo(int x, int y){

		asd = new string[x * y];

	}

	void print(){

		cout << asd[1][1];
	}

};


int main(){


	foo bruh(10, 10);

	bruh.print();

	return 0;
}
