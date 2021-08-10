#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> foo( unique_ptr<int> ptr1 )
{   
    unique_ptr<int> ptr;

    ptr.reset(new int(10));

    return ptr;
}

int main( void )
{
    unique_ptr<int> ptr1;
    
    ptr1.reset(new int(1));

    cout << *ptr1 << endl;

    foo(ptr1);

    cout << *ptr1 << endl;
}

