// CPP program to illustrate
// concept of Virtual Functions

#include <iostream>
using namespace std;

class base {
public:
	base( )
	{
		cout << "Constructor of the base class" << endl;
	}

	static void print()
	{
		cout << "print base class" << endl;
	}

	private:
	static int static_var;

};

int main()
{
	base* bptr;

	// Non-virtual function, binded at compile time
}








