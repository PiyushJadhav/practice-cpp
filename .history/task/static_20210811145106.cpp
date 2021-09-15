// CPP program to illustrate
// concept of Virtual Functions

// static member function
// static members exist as members of the class rather than as an instance
// *this* keyword is not available within the static member function
// The functions can be used without even creating the objects

// static data member
// The static data member - has only one instance shared by all the objects created
// Need to be initialed ( usually outside the class which implements it.)
// The can be accessed using class::my_static_p or T.my_static_param or T->my_static_p, based on T evaluating my class..

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

int base::static_var = 0;

int main()
{
	base* base_ptr;
}








