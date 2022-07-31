#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> fn_unique_value( unique_ptr<int> A )
{
    *A = 11;
    cout << "From : fn_unique_value " << *A << endl;

    unique_ptr<int> B{new int(*A+1)};

    return B;
}

/**
 * Pass by reference for smart pointer is not good idea. This is just for example though.
 * As pass by reference can let you keep with actual vars of same pointer. But the owndership of the resource if with both! :O! 
 *  
 */ 
unique_ptr<int> fn_unique_reference( unique_ptr<int>& A )
{
    *A = 11;
    cout << "From : fn_unique_reference " << *A << endl;

    unique_ptr<int> B{new int(*A+1)};

    return B;
}

shared_ptr<int> fn_shared_value( shared_ptr<int> A )
{
    *A = 11;
    cout << "From fn_shared_value " << *A << " with count " << A.use_count() << endl;
    shared_ptr<int> B{new int(*A+1)};
    return B;
}


/**
 * Pass by reference for smart pointer is not seen as some good practice, since you defy the use of the smart pointer as you do not increase the use_count()
 * Alternative could be to create a new param from shared ptr just to keep it alive.
 */ 
shared_ptr<int> fn_shared_reference( shared_ptr<int>& A )
{
    *A = 11;
    cout << "From fn_shared_reference " << *A << " with count " << A.use_count() << endl;
    shared_ptr<int> B{new int(*A+1)};
    return B;
}

int main ( void )
{
    // smart pointers

    // 1. unique_ptr

    // 1.1.a using rvalue, directly initialised
    // The new param is temp created and cannot be assessed with it's name
    unique_ptr<int> ptr1 = fn_unique_value( unique_ptr<int>( new(int)) );
    cout << "1.1.a From main: " << *ptr1 << endl;

    // 1.1.b using the ptr1 directly but as rvalue, with move.
    // Remember std::move is not moving but just casting, actual move will happen in function.
    // Q. Where does the actual move happens? It might happen in the function or not.       
    ptr1 = fn_unique_value(std::move(ptr1));
    cout << "1.1.b From main: " << *ptr1 << endl;

    // 1.2 forwarding using a reference
    auto ptr1_new = fn_unique_reference(ptr1);
    cout << "1.2 From main: " << *ptr1 << endl;
    

    // 2. shared_ptr
    // examples for forwarding the share pointer
     
    // 2.1 pass by value shared ptr
    // 2.1.1 rvalue 
    shared_ptr<int> ptr_s = fn_shared_value( shared_ptr<int>( new(int)) );
    cout << "2.1.a From main: " << *ptr_s << " with count " << ptr_s.use_count() << endl;

    // 2.1.b lvalue
    // shared_ptr<int> ptr_s;
    ptr_s = fn_shared_value( ptr_s );
    cout << "2.1.b From main: " << *ptr_s << " with count " << ptr_s.use_count() << endl;

    // 2.2 pass by reference -> DOES not increase the count, just forwards ptr to be used.
    ptr_s = fn_shared_reference( ptr_s );
    cout << "2.2 From main " << *ptr_s << " with count " << ptr_s.use_count() << endl;


    // 3.1 weak pointer
    // Weak pointer are used for tracking the object and is managed by shared_ptr only. 
    // Weak pointer does not own the object, but if needs to it can be converted to shared_ptr (temporarily) to gain ownership, only if the object exist.
    // ptr_wk.lock() - return shared pointer if the pointer exists, else default-constructed shared_ptr of type T.  
    weak_ptr<int> ptr_wk = ptr_s;
    if( auto ptr_got = ptr_wk.lock() )
    {
        cout << "Weak ptr was found: " << *ptr_got << endl;
    }
    else
    {
        cout << "Weak ptr was destroyed." << endl;
    }


    return 0;
}