# Repo for learning concourrency in C++

## Basic

### Thread creation

- <thread> lib in c++
- way to create threads
  -
  - funtion pointers
  
  - function objects
  
  - lamda functions in c++
    
    - here [] is capture list for local variables in the scope
      
      - can be passed using pass by value and reference
      
      - () - argument list
      
      - {} - function body
    
    - these function can be passed directly to thread like
    
    - ```cpp
      int a;
      auto some_thread_func = [&a](){ std::cout << "hello" ;};
      auto some_func = [](auto i, auto j) {
          // body
      };
      thread th([&a](){ std::cout << "hello" ;});
      
      
      
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

## Thread sync

- one of the important things to do in multithreading is to wait for one thread to execute critical section of the code to complete a part of code which is required to run simultaneously not parrelly 

- for eg -  only thread should have access to balance__amt when updating the balance
  
  if more than one threads have access to balance__amt  then it might have dirty write or maynot write synchronously since threads initiate and end their lifecycle according to the CPU not to the program
  
  Therefore we must have ways to sync the threads to work in synchronised order or stop them from accessing the critical sections for 1 thread at a time we use *mutex* for this. 
  
  For synchronised threads execution we will talk about it later
  
  [Synchronization (computer science) - Wikipedia](https://en.wikipedia.org/wiki/Synchronization_(computer_science)#Thread_or_process_synchronization)  read the example of 3 process for syncing their access to crtical sections of the code

- 
