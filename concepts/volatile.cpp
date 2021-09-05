
// Use of volatile in embedded Cpp
// It is confirmed that volatile use is going to be restricted and limited in cpp20.
// The CV qualifiers is still going to used and allowed
// The change only affects with statements with multiple side effects
// But the sequence points and side effects are going to be depricated

// volatile is needed in embedded when we deal with hardware which is 
// also responsible for changing the memory which we access in code
// Before every use of the volatile member the MCU checks for the value (rereads)
// and does not rely on the cache value

// If the compiler detects that there are no side effects in between to use of the 
// volatile param, the compiler will use the value which it had in the cache
// But if the side effect is detect in between(may it be just calling a random function())
// Then the compiler re-reads the value from the memory

// advantage 
// rereads, so fresh value is present

// disadvantage 
// op= problems, has multiple side effects makes it slower as it access the bus often

// We can still use the volatile in cpp
// But performing operations with the variables will not allowed.

// Note the depricated property will only generate warning if is used

#include<iostream>

using namespace std;

int main( void )
{
    volatile int a;
    // develop example for volatile normal use with single side effect


    // multiple side effects

    // what is still allowed in cpp20

    // what is not allowed
}