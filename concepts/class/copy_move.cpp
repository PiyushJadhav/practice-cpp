#include <iostream>
#include <memory>

using namespace std;

class myclass
{
public:
    myclass( void )
    {
        cout << "My constructor" << endl;
    }

    ~myclass( void )
    {
        cout << "My destructor" << endl;
    }

    myclass( const myclass& other )
    {
        cout << "Copy constructor" << endl;
    }

    myclass& operator=( const myclass& other )
    {
        cout << "Copy assignment" << endl;
        return *this;
    }

    myclass( myclass&& other )
    {
        cout << "Move constructor" << endl;
    }

    myclass& operator=( myclass&& other )
    {
        cout << "Move assignment" << endl;
        return *this;
    }
};

myclass& foo( myclass& myVar )
{
    cout << "From foo" << endl;
    return myVar;
}

int main( void )
{
    myclass myObj;
    myclass a;
    a = std::move(myObj); // rvalue going into lvalue
    foo( myObj );
}