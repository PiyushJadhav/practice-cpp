#include <iostream>

using namespace std;

class ClassA
{
    int data;
    std::string name;

    public:
    ClassA()
    {
        std::cout << "in constructor" << std::endl;
    }

    ~ClassA()
    {
        std::cout << "in destructr" << std::endl;
    }

    ClassA(const ClassA& A)
    {
        std::cout << "in copy constructor" << std::endl;
        this->data = A.data;
        this->name = A.name;
    }

    ClassA& operator=(const ClassA& rhs){   
        // copy assignment
        std::cout << "in copy assignment" << std::endl;
        this->data = rhs.data;
        this->name = rhs.name;
        return *this;
    }

    ClassA(ClassA&& A)
    {
        std::cout << "in move constructor" << std::endl;
        this->data = A.data;
        this->name = A.name;
        A.name = std::string{};
    }

    ClassA& operator=(ClassA&& rhs)
    {
        if(this != &rhs)
        {
            std::cout << "in move assignment" << std::endl;
            this->data = rhs.data;
            this->name = rhs.name;
            rhs.name = std::string{};

            // destroy rhs
        }

        return *this;
    }

};

int main()
{
    // ClassA A; // side: How can you improve this?
    // ClassA B = A; // what will be called
    
    
    ClassA C; 
    ClassA D(C); // what will be called

    return 0;
}



