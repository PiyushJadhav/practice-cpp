#include <functional>
#include <iostream>
#include <set>

using namespace std;

// perfect forwarding is used in a function which takes a rvalue reference and uses this value to pass into subsequent function
// When passing this ravlue reference into another function is forwarding is not used, it is given as lvalue reference
// and the rvalue ness is lost since the param is no longer rvalue


void func_ref(int& a)
{
    cout << "lvalue ref " <<__FUNCTION__ << a << endl;
}

void func_ref(int&& a)
{
    cout << "rvalue ref "<<__FUNCTION__ << a << endl;
}

void wrapper(int&& a)
{
    func_ref(forward<int>(a));
    cout << __FUNCTION__ << a << endl;
}

int main(void)
{      
    int a = 0;
    wrapper(move(a));
}