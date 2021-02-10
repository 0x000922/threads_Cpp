#include <iostream>
#include <thread>
using namespace std;

int main()
{
    int i = 10;

    thread th([](){ 
        cout << "hello "; 
    });
    th.join();

    // basic lamda functions
    auto somefunc = []() { cout << "hello "; };
    somefunc();
    
    // lamda function with using of local variable call by value s
    auto func = [i](int a) {
        return a + i;
    };
    cout << func(5);
    // lamda parameters with call by refrence
    auto func1 = [&i](int a){
        i = 7;
        return a + i;
    };
    cout << endl << func1(10) << " " <<  i;
}   