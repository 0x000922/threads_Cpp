#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "Hello from thread_functions";
}

int main()
{
    std::thread th(thread_function);
    std::cout<< "from main";
    th.join();

}