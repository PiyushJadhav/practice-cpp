// facade 

#include "system.hpp"

class facade
{
    system1 *sys1 = nullptr;
    system2 *sys2 = nullptr;

public:
    facade( int a, int b );

    ~facade();

    int process();

};
