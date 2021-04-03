# Repo for learning Multithreading in C++

## Basic

### Thread vs process

- | Process                                                                                                                                                                                                                                                                                                    | thread                                                                                                                                                                            |
  |:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  | In windows terms **process** is a much broader part of application. A process is independent in existance and has it's own address space, security context, identifier. And a primary threads. This primary thread can spawn other worker thread. *commmon for all platforms* just read from windows docs. | A thread can execute work for a process therefore they share the same address space as the process it spawns. They can enable them to share between more than one worker threads. |
  | In short the process has a independent existance of memory and is has it's own address space. It can spawn thread for work                                                                                                                                                                                 | A thread is unit of work of a application. A unit which can scheduled for execution.                                                                                              |

### A note of thread's context of execution

- As threads can be scheduled for execution they have their registers, stack for execution.

- A unique point is that even though threads can have a have user address space they can have diffrent permission than the process from which it was spawned this is also called impersonation ( a thread having diffrenent permission to mimic a client on the order side of the server. for eg remote servers with users having root / admin access. The remote process maynot have higher inherit permission but the person using the service may be working with higher permissions stage )

### Thread creation

- <thread> lib in c++

- way to create threads
  -
  
  - funtion pointers
  
  - function objects
  
  - lamda functions in c++
    
    - here [] is capture list for local variables in the scope
      
      - [&] passing all variables ( in scope where function resides ) by **reference**
      
      - [=] passing all ( in scope where function resides )by **value**      
        can be passed using pass by value and reference
      
      () - argument list
      
      {} - function body
    
    - these function can be passed directly to thread like
    
    - ```cpp
      int a;
      auto some_thread_func = [&a](){ std::cout << "hello" ;};
      auto some_func = [](auto i, auto j) {
          // body
      };
      
      thread th([&a](){ 
      std::cout << "hello" ;
      // passing of variable surrounding by value
      });
      thread th([=](){
          // body
          // passing surrounding variables by value
      });
      ```

- ```cpp
  void thread_function()
  {
      std::cout << "Hello from thread_functions";
  }
  main()
  {
      std::thread th(thread_function);
      vector<std::thread> th_vector;
      // we can also push thread to vector a call them
      for(int i = 0; i < 2; i++)
      {
          th_vector.push_back()
      }
  }
  ```

- ### Passing parameters in threads
  
  - We can pass an argument list to function when passing them to threads
    
    ```cpp
    auto fn = [](int a, int b){
        std::cout << a + b;
    };
    std:: thread th(fn,1,2); // 3
    ```
  
  - Keep in mind that thread functions can't return any values ( they can but we can't use those values). Therefore we must update the references to get answers from the threads.  There are other ways to avoid using references. C++ has constructs to use return values from the functions used in async in c++
    
    ```cpp
    void ret_refer_int(int b, int &a){
        a = b + 1;
        a
    }
    ```
    
    
