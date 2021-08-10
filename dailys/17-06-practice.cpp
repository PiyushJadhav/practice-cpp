#include <iostream>

using namespace std;

class base
{
    public:
};

class derived : public base
{
    public:

};

int main ( void )
{
    derived d;
    base* b = &d;
}