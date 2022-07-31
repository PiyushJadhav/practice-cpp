#include <iostream>
#include <future>
using namespace std;

int race_finish(int N)
{   
    int complete_cars = 20;
    cout << "race is finished" << endl;
    return complete_cars;
}

int who_won(future<int>& f1)
{
    int car = f1.get(); // if not set, then exception
    cout << "car won: " << car << endl;
    return car;
}

int finish_race(shared_future<int> sf)
{
    int n = sf.get();
    cout << "time is " <<  n << endl;

    return n;
}

int main()
{
    cout << "1. Grid start - Future only - pass values from child to parent" << endl;

    int cars = 20;
    std::future<int> f1 = async(launch::async, race_finish, cars); // new thread
    // std::future f1 = async(launch::deffered, race_finish, cars); // no new thread
    // std::future f1 = async(launch::deffered | launch::deferred, race_finish, cars); // default, depends on impl
    int n = f1.get();

    cout << "completed cars " << n << endl;

    cout << "2 Grid start - Future and promise - value from parent to child" << endl;
    promise<int> p;
    future<int> f21 = p.get_future();

    std::future<int> f22 = async(launch::async, who_won, ref(f21));
    
    cout << "setting the winner" << endl;
    p.set_value(77);

    cout << "3. children - share future" << endl;
    promise<int> p1;
    shared_future<int> shared_f= p.get_future();

    std::future<int> f321 = async(launch::async, finish_race, shared_f);
    std::future<int> f322 = async(launch::async, finish_race, shared_f);
    std::future<int> f323 = async(launch::async, finish_race, shared_f);

    p1.set_value(75);
}

