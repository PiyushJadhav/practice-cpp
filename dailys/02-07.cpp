#include <iostream>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<int, int> mp;

    map<int, int>::iterator itr = mp.find(1);

    if( itr != mp.end() )
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    mp.insert( std::pair<int,int> (1,1) );
}
