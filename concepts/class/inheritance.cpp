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

	void try_this( void )
	{
		cout << "from base override - should call inherited one if is inherited" << endl;
		this->print();
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
	cout << "1. virtual function, binded at runtime" << endl;
	bptr->print();

	// Non-virtual function, binded at compile time
	cout << "2. Non-virtual function, binded at compile time" << endl;
	bptr->show();

	// use this* from base
	cout << "3. Test this*" << endl;
	bptr->try_this();
}

