### Thread sync controls and managing shared data

##### Thread sync

1. one of the important things to do in multi threading is to wait for one thread to execute critical section of the code to complete a part of code which is required to run simultaneously not in parallel 

2. for eg - only thread should have access to balance__amt when updating the balance if more than one threads have access to balance__amt then it might have dirty write or may not write synchronously since threads initiate and end their life-cycle according to the CPU not to the program. Therefore we must have ways to sync the threads to work in synchronized order or stop them from accessing the critical sections for 1 thread at a time we use *mutex* variable for this.
   
   [Synchronization (computer science) - Wikipedia](https://en.wikipedia.org/wiki/Synchronization_(computer_science)#Thread_or_process_synchronization) read the example of 3 process for syncing their access to critical sections of the code
- summary -
  
  why do we need to control it ?
  
  - avoid dirty reads + dirty writes in program can produce inconsistent values while operation of a functions
  
  - The core of the problem in syncing threads is the read and write operations which seam to be atomic operations are not actually atomic ( either the operation happens or it doesn't there is no midway )
  
  - one way of solving this problem is locking the resource when in use so that no other thread can access it until the thread release the lock which is implemented using  **mutex** variable 
  
  - ```cpp
    using namespace std;
    std::mutex mtxv
    ```  
  
  - 
