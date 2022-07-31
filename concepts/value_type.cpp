// covers what are different types of values
// rvalue and lvalue
// glvalue generalised lvalue
// prvalue - pure rvalue
// xvalue - experied rvalue
// lvalue - glvalue and not xvalue
// rvalue - prvalue or xvalue

// ++a is lvalue
// a++ is rvalue
#include<iostream>

void func(int& a)
{
    std::cout << a << " lvalue ref overload" << std::endl;
}

void func(int&& a)
{
    std::cout << a << " rvalue ref overload" << std::endl;
}

int main()
{

    int a = 0;
    ++a;
    std::cout << "++a:" << a << std::endl;
    func(++a);

    a++;
    std::cout << "a++:" << a << std::endl;
    func(a++);
}
