#include <iostream>
using namespace std;

class Base
{
    protected:
    static int temp;

    public:
    virtual void foo( void )
    {
        cout << "from Base" << endl;
    }

    Base()
    {
        cout << "Contr Base" << endl;
    }

    virtual ~Base()
    {
        cout << "Destr Base" << endl;
    }

};

class Derived: public Base
{
    public:


    Derived()
    {
        cout << "Constr of Derived" << endl;
    }

    void foo( void )
    {
        cout << "From Derived" << endl;
    }

    ~Derived()
    {
        cout << "Destr Derived" << endl;
    }
};

int main( void )
{
    Derived* derived = nullptr;
    derived = new Derived();
    cout << "Inside try" << endl;
    Base* base = derived;
    base->foo();
    delete base; 
    cout << "Exiting  block." << endl;
}