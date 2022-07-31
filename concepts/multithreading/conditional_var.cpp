#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <future>
#include <queue>

/* Using mutex to synchronize threads */
std::mutex m_mutex;
std::condition_variable m_conditional_variable;

using namespace std;

// resource
std::queue<int> q;

void producer()
{
    for (int i=0; i<100; i++)
    {
        unique_lock<mutex> lk(m_mutex);
        q.push(i);
        m_conditional_variable.notify_all();
        cout << __FUNCTION__ << " notified: " << i << endl;
    }
}

void consumer()
{
    for(int i=0; i<100; i++)
    {
        unique_lock<mutex> lk(m_mutex);
        m_conditional_variable.wait(lk, [](){return !q.empty();});
        cout << __FUNCTION__ << " consumed: " << q.front() << endl;
        q.pop();
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
}