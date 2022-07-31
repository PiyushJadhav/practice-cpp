#include <iostream>
using namespace std;

int main ( void )
{   

    // cpp casting is very similar to the C casting. There is nothing fancy in terms of functional addition.
    // Only difference is that the castings are done with more checks to it is easy to spot errors.

    // There are three types of casting - const_cast, static_cast, dynamic_cast, reinterpret_cast
    // 1. static casting - is performed at compile time. Is the most straight forward use of type conversions in cpp.
    uint16_t a = 65535;
    int16_t b = static_cast<int16_t>(a);
    cout << "1.1 Static cast " << a << endl;

    // 2. const casting
    // casting used for removing const or volatile of a variable. The base type will be the same except the alteration of const and volatile. 
    const int i = 3;
    int* ptr_i = const_cast<int*>(&i);
    *ptr_i = 4;      // undefined behavior - Do not use such way
    std::cout << "2.1 Use of const_cast on int: " << *ptr_i << std::endl;

    int i = 3;
    const int& ref_i = i;
    const_cast<int&>(ref_i) = 4;      
    std::cout << "2.2 Use of const_cast on int reference: " << *ptr_i << std::endl;
    
    struct type
    {
        int i;
        type(): i(3) {}
        
        void f(int v)
        {
            this->i = v;   
        }

        void f_const(int v) const
        {
            // this->i = v;                     // compile error: this is a pointer to const
            const_cast<type*>(this)->i = v;     // OK as long as the type object isn't const
        }
    };

    type ty;
    ty.f(0); // okay as method is not const
    ty.f_const(1); // okay as well since const_cast is used on this 

    // function pointer
    void (type::* func_ptr)(int) const = &type::f_const; // pointer to member function
    // const_cast<void(type::*)(int)>(pmf);   // compile error: const_cast does
                                              // not work on function pointers

    // 3. dynamic casting
    // Is performed at runntime. If is not possible returns null_ptr.
    // Safely converts pointers and reference to classes up, down or sideways along the inheritance hierarchy

    struct Base
    {
        virtual ~Base() {}
    };
    
    struct Derived: Base
    {
        virtual void name() {}
    };

    Base* b1 = new Base;
    if (Derived* d = dynamic_cast<Derived*>(b1); d != nullptr)
    {
        // not possible to upcast
        std::cout << "downcast from b1 to d successful\n";
        d->name(); // safe to call
    }
 
    Base* b2 = new Derived;
    if (Derived* d = dynamic_cast<Derived*>(b2); d != nullptr)
    {
        std::cout << "downcast from b2 to d successful\n";
        d->name(); // safe to call
    } 
    delete b1;
    delete b2;

    // 4. reinterpret casting
    // Is like type punning, can convert the any type into other, without loss of any property, so on revert cast you can get back the type as it was.
    // Converts between types by reinterpreting the underlying bit pattern

    int i = 7;
    // pointer to integer and back
    std::uintptr_t v1 = reinterpret_cast<std::uintptr_t>(&i); // static_cast is an error
    std::cout << "The value of &i is " << std::showbase << std::hex << v1 << '\n';
    int* p1 = reinterpret_cast<int*>(v1);
    assert(p1 == &i);
}