#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m_mutex;

class wthread
{
    public:
    wthread(thread t)
    {
       m_t = std::move(t); // what is happening here? Thread swap is called, rhs is rvalue.
    }
    ~wthread()
    {
        m_t.join();
    }

    private:
    std::thread m_t;
};

void funct1()
{
    for(int i = 0; i < 100; i++)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        cout << "from funct1: " << i << endl;
        
    }
}

int main(void)
{
    wthread wt((std::thread(funct1))); // no need to join, RAII will take care of it

    for(int i = 0; i < 100; i++)
    {    
        std::lock_guard<std::mutex> guard(m_mutex);
        cout << "from main: " << i << endl;
    }

}