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

    virtual void a ( int inputp) = 0;

	void show()
	{
		cout << "show base class" << endl;
	}
};

int main()
{
	base* bptr;

	// Non-virtual function, binded at compile time
}








