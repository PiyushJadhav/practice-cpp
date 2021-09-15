// CPP program to illustrate
// concept of Virtual Functions

// static member function
// static members exist as members of the class rather than as an instance
// *this* keyword is not available within the static member function
// The functions can be used without even creating the objects
// The member functions cannot be virtual, const or volatile.
// The address cannot be stored in pointer to member function address.

// static data member
// The static data member - has only one instance shared by all the objects created
// Need to be initialed ( usually outside the class which implements it.) For const static type, it can be done inside the class, for constexpr static it must be inside class.
// The can be accessed using class::my_static_p or T.my_static_param or T->my_static_p, based on T evaluating my class..
// Cannot be muttable - list etc., has to have defined memory at beginning.
//
#include <iostream>
using namespace std;

class base {
public:
    base( )
    {
        cout << "Constructor of the base class" << endl;
    }


    // cannot be vitual, const or volatile
    static void print()
    {
        // cannot modify non static variable
        // non_static_var = 1; // error

        // does not have access to it either
        // static_var = non_static_var; // error

        // only can access and modify static non const variables
        static_var = 2;
        static_var = const_static_var;
        cout << "print base class" << endl;
    }

    private:
    int non_static_var;

    // static - type - cannot be mutable, need to know the memory at definition
    static int static_var;

    // for const static object - it is allowed to define value
    const static int const_static_var = 10;

    // constexpr has to be defined within the class
    constexpr static int constexpr_static_var = const_static_var;

};

// need to define it outside the class - for non const
int base::static_var = 0;

// const int base::const_static_var = 1; // also allowed, but either one

int main()
{
    // can call the class's function (not method) without even defining a object
    base::print();

    // base class obj
    base* base_ptr;


}








