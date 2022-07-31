#include<iostream>
using namespace std;


class A{

    public:
    virtual void func()=0;
    
    A(){
        cout<<"A ";
    }
};
class B: public A
{
    public:
    B(){
        cout<<"B ";
    }

    void func()
    {
        cout << "in B";
    }
};

int main(){
A *a=new B();
a->func();

return 0;