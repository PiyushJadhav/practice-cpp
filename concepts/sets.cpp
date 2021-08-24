#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main( void )
{
    set<string> s1;

    string str;
    cin >> str;

    cout << str << endl;
    
    s1.insert("Hello");
    s1.insert("world");
    if( s1.find("Hello") != s1.end() )
    {
        cout << "already present" << endl;
    }

    set<string>::iterator itr;

    for (itr = s1.begin(); itr != s1.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout << endl;
}