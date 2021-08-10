#include <iostream>
using namespace std;

int main ( void )
{   

    // cpp casting is very similar to the C casting. There is nothing fancy in terms of functional addition.
    // Only difference is that the castings are done with more checks to it is easy to spot errors.

    // There are three types of casting - const_cast, static_cast, dynamic_cast, reinterpret_cast
    // 1. static casting - is performed at compile time.
    int a;

    // 2. const casting
    // casting used for removing const or volatile of a variable. The base type will be the same except the alteration of const and volatile. 


    // 3. dynamic casting
    // Is performed at runntime. If is not possible returns null_ptr.
    
    // 4. reinterpret casting
    // Is like type punning, can convert the any type into other, without loss of any property, so on revert cast you can get back the type as it was.

}