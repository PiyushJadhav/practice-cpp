// CPP program to illustrate
// concept of Virtual Functions

#include <iostream>
using namespace std;

void * p;

class base {
public:
    base( )
    {
        cout << "Init the base class" << endl;
    }

	virtual void print()    
	{
		cout << "print base class" << endl;
	}

    virtual void a ( int inputp) = 0;

	void show()
	{
		cout << "show base class" << endl;
	}
};

class derived : public base {
public:
    derived( int a )
    {
        cout << "Init derived with " << a << endl;
    }

	void print()
	{
		cout << "print derived class" << endl;
	}

    void a( int inputp)
    {
        
    }

	void show()
	{
		cout << "show derived class" << endl;
	}
};

int main()
{
	base* bptr;  
	derived d(940);
	bptr = &d;

	// virtual function, binded at runtime
	bptr->print();

	// Non-virtual function, binded at compile time
	bptr->show();
}








