// practicing some smart pointers

#include <iostream>
#include <memory>

using namespace std;

void func( shared_ptr<int> a )
{

}

int main( void )
{
    shared_ptr<int> A(new int(1));
    func(A);
}