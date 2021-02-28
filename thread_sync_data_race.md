### Thread sync controls and managing shared data

##### Thread sync

1. one of the important things to do in multithreading is to wait for one thread to execute critical section of the code to complete a part of code which is required to run simultaneously not parrelly

2. for eg - only thread should have access to balance__amt when updating the balance if more than one threads have access to balance__amt then it might have dirty write or maynot write synchronously since threads initiate and end their lifecycle according to the CPU not to the program. Therefore we must have ways to sync the threads to work in synchronised order or stop them from accessing the critical sections for 1 thread at a time we use *mutex* for this. For synchronised threads execution we will talk about it later
   
   [Synchronization (computer science) - Wikipedia](https://en.wikipedia.org/wiki/Synchronization_(computer_science)#Thread_or_process_synchronization) read the example of 3 process for syncing their access to crtical sections of the code
- summary -
  
  why do we need to control it ?
  
  - avoid dirty reads + dirty writes in program can cause inconsistant values while operation of a functions
  - one way of solving this problem is locking the resource when in use so that no other thread can access it until the thread release the lock which is implemented using  **mutex** variable 
  - we can also try to make the update an atomic operation since these are not atomic operations when we see their actual machine code their can be premption (changing or stopping current thread to excute other threads) of threads while updating which can lead to dirty reads or writes. Above mentioned have been implemented examples later
  - 
  
  - ```cpp
    using namespace std;
    std::mutex mtxv
    ```


