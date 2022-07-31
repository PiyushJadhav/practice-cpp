#include <functional>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

function<bool(int a, int b)> set_compare = [](int a, int b)->bool{
    std::stringstream sa, sb;
    sa << a;
    sb << b;
    return sa.str() > sb.str();
};

// sets are containers with ordered params
// the order can be deduced for customs types with custom provided comparator
// following the comparator is passed into the set declaration and definiation
std::set<int, decltype(set_compare)> mySet = {{1,2,5,7,9,11,34,123,354,54,323,67,45,76,87}, set_compare};


// template function 
template<typename n, typename cmp>
auto operator<<(std::ostream& os, const set<n, cmp>& s) -> std::ostream&
{
    for(auto const& itr: s)
    {
        os << itr << endl;
    }
    return os;
}

int main( void )
{
    cout << mySet << endl;
}