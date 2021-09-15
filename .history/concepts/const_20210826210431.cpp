// Work example for const

// Const, volatile or const-volatile can be the type of the functions in cpp
// the const qualifies comes after the arg list in definition
// const function can only call other const functions, and other non-const function by casting (if applicable)
// it can also modify other function by other access path
// ref-qualifer member functions with & or && after arg list in definition

// Const object
// can call only const specifier functions
// can't change the var for const class
// var has to be mutable type to change
// any attempt to change is compiler error
// needs to be intialised at definition

// const member function
// can be only called by const object and non const objects
//
//

#include <stdio.h>
#include <iostream>

using namespace std;

class ref_qualifier
{
public:
    ref_qualifier( void )
    {

    }

    void fn( void ) &
    {
        std::cout << "ref-qualifier lvalue" << std::endl;
    }

    void fn( void ) &&
    {
        cout << "ref-qualifer rvalue" << endl;
    }

};

int main( void )
{

}
