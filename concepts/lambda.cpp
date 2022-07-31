#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

std::mutex m1;
std::mutex m2;
int globalVar1 = 0;
int globalVar2 = 0;


struct A{
    
    A(int a, int b) { std::cout << "Parameterized" << '\n'; }
};

int main() {
   
   int m = 8;
   auto f = [m](int a, int b) mutable{
    m++;
    return (a + b + m);
    };

auto result = f(2, 2);
    return 0;
}