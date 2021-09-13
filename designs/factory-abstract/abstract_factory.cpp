// Abstract factory pattern

#include <iostream>
#include <string.h>

using namespace std;

class factory_af
{
    public:
    factory_af()
    {
        cout << "Constructor of factory_af" << endl;
    }

    ~factory_af()
    {
        cout << "Destructor of factory_af" << endl;
    }

    chair C;
    sofa S;
};

class factory_victorian : public factory_af
{
    factory_victorian()
    {
        cout << "Constructor of factory_vict" << endl;
    }

    ~factory_victorian()
    {
        cout << "Destructor of factory_vict" << endl;
    }
};

class factory_mod : public factory_af
{
    factory_mod()
    {
        cout << "Constructor of factory_mod" << endl;
    }

    ~factory_mod()
    {
        cout << "Destructor of factory_mod" << endl;
    }
};

class chair
{
    chair()
    {

    }

    ~chair()
    {

    }
};

class chair_victorian : public chair
{

};

class chair_modern : public chair
{

};

class sofa
{

};

class sofa_victorian: public sofa
{

};

class sofa__modern: public sofa
{

};

int main( void )
{
    // AF 



    return 0;
}