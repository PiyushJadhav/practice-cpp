#include <iostream>
#include "facade.hpp"

using namespace std;

facade::facade( int a, int b)
{
    cout << "Facade init with param" << a << "and " << b << endl;

    sys1 = new system1;
    sys2 = new system2;
};

facade::~facade()
{
    cout << "Deleting Facade." << endl;
    delete sys1;
    delete sys2;
}

int facade::process()
{
    cout << "Processing facade." << endl;
    int a = sys1->system_process();
    int b = sys2->system_process();
    
    return (a + b);
}