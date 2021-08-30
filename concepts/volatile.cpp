
// Use of volatile in embedded Cpp
// It is confirmed that volatile use is going to be restricted nd limited in cpp20.
// The CV qualifiers is still going to used and allowed.
// But the sequence pointer and side effects are going to be depricated.

// volatile is need in embedded when we deal with hardware changing the values.
// Before every use of the volatile member the MCU checks for the value (rereads)
// and does not rely on the cache value

// advantage 
// rereads, so fresh value is present

// disadvantage 
// op= problems, rereads within a expression with side effects making it slower

// We can still use the volatile in cpp
// But performing operations with the variables will not allowed.

#include<iostream>
