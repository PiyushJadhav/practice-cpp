// move semantics

#include <iostream>
#include <vector>

using namespace std;

int main( void )
{
    cout << "Start" << endl;

    vector<int> A;

    for( int i=0; i<20; i++ )
    {
        A.push_back(i);
    }

    cout << A.at(10) << endl;

    vector<int> B;

    B = A;

    cout << &A << endl;

    cout << &B << endl;

}