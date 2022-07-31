#include <iostream>
#include <vector>

using namespace std;

class base {
public:

    base()
    {
        cout << "constructor base" << endl; 
    }

    virtual void print()
    {
        cout << "print base class\n";
    }
    
    void show()
    {
        cout << "base show\n";
    }

    base(const base& given)
    {
        cout << "base copy constructor" << endl;
    }

    base(base&& given) noexcept
    {
        cout << "base move constructor" << endl;
    }

    base& operator=(const base& rhs)
    {
        cout << "base copy assignment called" << endl;
        return *this = base(rhs);
    }

    base& operator=(base&& rhs) noexcept
    {
        cout << "base move assignment called" << endl;
        return *this;
    }
};
    
class derived : public base {
public:
    derived()
    {
        cout << "derived constructor" << endl; 
    }

    void print()
    {
        cout << "print derived class\n";
    }
    
    void show()
    {
        cout << "show derived class\n";
    }

    derived(const derived& tmp)
    {
        cout << "derived copy" << endl;
    }
};
    
void use_unique_reference(const unique_ptr<vector<int>>& b)
{
  // do something
  cout << "reference called\n";
}

void use_unique( unique_ptr<vector<int>> b )
{
  cout << "normal called\n";
}

shared_ptr<base> func_ptr(shared_ptr<base> _base, bool cond)
{
    cout << __FUNCTION__ << "share count " << _base.use_count() <<  endl;
    return _base;
}

base func_obj(base _base)
{
    cout << __FUNCTION__ << " elided" << endl;
    return _base;
}

base func_obj(base _base, bool cond)
{
    cout << __FUNCTION__ << " not elided?" << endl;
    return cond ? _base: base();
}

int main()
{
    //base* bptr; // problems?
    auto d = make_shared<derived>();
    shared_ptr<base> bptr = d;
    cout << "shared count " << d.use_count() << endl;

    // Virtual function, binded at runtime
    bptr->print();
    // Non-virtual function, binded at compile time
    bptr->show();
    
    // use unique ptr
    cout << "1. use reference" << endl;
    auto unq = make_unique<vector<int>>();
    use_unique_reference(unq);
    cout << unq->size() << endl;

    cout << "2. Use move" << endl;
    auto unq1 = make_unique<vector<int>>();
    use_unique(move(unq1));
    // cannot use below seg fault since it is moved but is not check compile time
    // cout << unq1->size() << endl;

    
    // Various ways to create obj
    cout << "3. Initialisation" << endl;
    cout << "3.1. Raw way to make object, prefer make_unique or make_shared" << endl;
    base b1;
    b1.show();

    cout << "3.2. Using temp obect with {} init" << endl;
    base b2{base()};

    cout << "3.3. Using copy" << endl;
    base b3 = b2;
    base b31 = base(b3);

    cout << "3.4. using move" << endl;
    base b4 = move(b2);

    cout << "4.1 Pass by ptr and return shared ptr" << endl;
    shared_ptr<base> shrd_base = make_shared<base>();
    shared_ptr<base> shrd_base1 = shrd_base;
    shared_ptr<base> ret_base = func_ptr(shrd_base, false);

    cout << "Returned Share count " << shrd_base.use_count() <<  endl;

    cout << "4.2.1 Pass by value - copy elision with created objects" << endl;
    base base421;
    base base4211 = func_obj(base421);

    cout << "4.2.2 Pass by value - No copy elision with created objects" << endl;
    base base422;
    base base4212 = func_obj(base422, true);

    cout << "4.2.3 Pass by rvalue - copy elision with created objects" << endl;
    base base423;
    base base4231 = func_obj(move(base421));

    return 0;
}
