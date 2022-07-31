// Factory Pattern

#include <iostream>
#include <string.h>

using namespace std;

class vehicle
{
public:
    vehicle()
    {
        cout << "From constructor of vehicle base class" << endl;
    }

    ~vehicle()
    {
        cout << "From destructor of vehicle base class" << endl;
    }

};

class car: public vehicle
{
    public:
    car()
    {
        cout << "From constructor of car" << endl;
    }

    ~car()
    {
        cout << "From destructor of car" << endl;
    }
};

class bike: public vehicle
{
    public:
    bike()
    {
        cout << "From constructor of bike" << endl;
    }

    ~bike()
    {
        cout << "From destructor of bike" << endl;
    }
};

class creator
{
public:
    creator()
    {
        cout << "From constructor of creator" << endl;
    }

    ~creator()
    {
        cout << "From destructor of creator" << endl;
    }

    virtual vehicle* factoryMethod()
    {
        cout  << "FROM factory of creator" << endl;
        return nullptr;
    }

    void operation()
    {
        cout << "From operation of creator" << endl;
        vehicle* machina = this->factoryMethod();

    }
};

class createCar: public creator
{
    public:
    createCar()
    {
        cout << "From constructor of createCar" << endl;
    }

    ~createCar()
    {
        cout << "From destructor of createCar" << endl;
        delete machina;
    }

    vehicle* factoryMethod()
    {
        cout << "FROM factory of createCAR" << endl;
        machina = (new car());
        return machina;
    }

    private:
    car* machina;

};


class createBike: public creator
{
    public:
    createBike()
    {
        cout << "From constructor of createBike" << endl;
    }

    ~createBike()
    {
        cout << "From destructor of createBike" << endl;
        delete bici;
    }

    vehicle* factoryMethod()
    {
        cout << "FROM factory of createBike" << endl;
        bici = new bike();
        return bici;
    }
    private:
    bike* bici;


};

class client
{
    public:
    client( creator* create )
    {
        cout << "From constructor of client" << endl;
        
        // create new obj of what I want
        create->factoryMethod();

        // following call also can be made for respective class 
        // create->factoryMethod();
    }

};


int main( void )
{
    {
        cout << "TEST 1. car" << endl;
        // create objects
        createCar cCar;
        client c( &cCar );
    }

    {
        cout << "TEST 2. bike" << endl;
        // create objects
        createBike cBike;
        client c( &cBike );
    }
    
    return 0;
}