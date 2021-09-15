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

base::static_var = 0;

int main()
{
	base* base_ptr;

	// Non-virtual function, binded at compile time
}








