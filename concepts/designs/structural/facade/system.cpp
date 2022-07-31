#include <iostream>
#include "system.hpp"

using namespace std;

system1::system1()
{
    cout << "From init of system1." << endl;
}

int system1::system_process()
{
    cout << "From process of system1." << endl;
    return this->ret_process;
}

system1::~system1()
{
    cout << "Deleting system 1." << endl;
}

system2::system2()
{
    cout << "From init of system2." << endl;
}

int system2::system_process()
{
    cout << "From process of system2." << endl;
    return this->ret_process;
}

system2::~system2()
{
    cout << "Deleting system 2." << endl;
}