#include <iostream>

class A{
    public:
        A() = default;
        A(int a, int b) { std::cout << "Parameterized" << '\n'; }
};

int main() {
    A a(); // look for function -Wvexing-parse
    A b(1, 2);
    A c;
    A d{A(1, 2)};
    A e{A()};

    return 0;
}