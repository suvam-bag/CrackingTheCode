/*Volatile in C*/

// The keyword volatile informs the comopiler that the value of the variable can change from outside, without any update to the code. 
//This maybe done by the operating system, the hardware, or another thread. Because the value can change unexpectedly, the compiler will
//therefore reload the value each time from the memory.

//Volatile variables are also useful when multi-threaded programs have global variables and any thread can modify these shared variables. 
//We may not want optimization on these variables.  

//volatile int
int volatile x;
volatile int x;

//volatile pointer
volatile int *x;
int volatile *x;

//volatile pointer to non-volatile data
int * volatile x;


