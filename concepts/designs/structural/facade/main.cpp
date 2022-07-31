
// Facade provides a easy to use API for the complex systems
// It is used when the client using the system, does not need to know the bit and bobs of the systems
// All it can do is to access the API and get it's work done.
// Facade helps to seperate the implementation from the interface

// Facade is not a part of the system nor the client.
// It is an independent layer which seperates the two. Client cannot directly call subsystem

// Facade manages the lifetimes of the subsystems

// Client -(Easy to use APIs)-> Facade -(handles the complex calls)-> Subsystem

#include <iostream>
#include "facade.hpp"

using namespace std;

int main( void )
{
    facade facade_obj(1, 2);
    facade_obj.process();
}

