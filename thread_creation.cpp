#include <iostream>
#include <string>
#include <thread>


using namespace std;
void thread_function()
{
    std::cout << "Hello from thread_functions" << "\n";
}

void thread_func_args(int a, string b)
{
    cout << a << " "<< b << "\n";
}
int main()
{
    // std::thread th(thread_function);
    std::cout<< "from main";
    // th.join();
    int i = 5;
    // using lamda functions     
    auto some_thread_func = [](){ 
        std::cout << "hello" ;
    };
    auto some_func_args = [=](int a, int b) {
        return a + b + i;
    }; 

    // ways of calling threads 
    
    thread t1(thread_function);
    t1.join();
    // function with args
    thread t2(thread_func_args, 3, "0x000922");
    t2.join();

    // passing lambda functions
    thread t3(some_thread_func);
    t3.join();


}