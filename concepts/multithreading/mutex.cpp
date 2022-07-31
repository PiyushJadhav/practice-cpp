#include <thread>
#include <mutex>
#include <iostream>
 
int g_i = 0;
std::mutex g_mutex1;
std::mutex g_mutex2;  

void safe_increment1()
{
    const std::lock_guard<std::mutex> lock(g_mutex1);
    const std::lock_guard<std::mutex> lock(g_mutex2);
    for(int i = 0; i < 10; i++)
    {
        ++g_i;
        std::cout << "g_i: " << g_i << "; in thread #"
              << std::this_thread::get_id() << '\n';
    }
}

void safe_increment2()
{
    const std::lock_guard<std::mutex> lock(g_mutex1);
    for(int i = 0; i < 10; i++)
    {
        ++g_i;
        std::cout << "g_i: " << g_i << "; in thread #"
              << std::this_thread::get_id() << '\n';
    }
}
 
int main()
{
    std::cout << "g_i: " << g_i << "; in main()\n";
    
    // we will enter the t1 and only release lock once the operation is done
    std::thread t1(safe_increment1);
    std::thread t2(safe_increment2);
 
    t1.join();
    t2.join();
 
    std::cout << "g_i: " << g_i << "; in main()\n";
}