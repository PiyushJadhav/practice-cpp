#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

class base
{
    public:
    base()
    {
        cout << "constr of base" << endl;
    }

    void set_a(int _a)
    {
        a = _a;
    }

    int get_a()
    {
        return a;
    }

    private:
    int a = 0;
};

void func_int(const unique_ptr<int> ptr)
{
    cout << __FUNCTION__ << *ptr << endl;
    *ptr = 1;
}

void func_int_ref(unique_ptr<int>& ptr)
{
    cout << __FUNCTION__ << *ptr << endl;
    *ptr = 2;
}

void func_int_ref(unique_ptr<int>&& ptr)
{
    cout << __FUNCTION__ << *ptr << endl;
    *ptr = 2;
}

void func_int_ref_const(const unique_ptr<int>& ptr)
{
    cout << __FUNCTION__ << *ptr << endl;
    *ptr = 3;
}

void func_class(unique_ptr<base> b)
{
    cout << __FUNCTION__ << b->get_a() << endl;
    b->set_a(1);
}

void func_class_ref(unique_ptr<base>& b)
{
    cout << __FUNCTION__ << b->get_a() << endl;
    b->set_a(2);
}

void func_class_ref_const(const unique_ptr<base>& b)
{
    cout << __FUNCTION__ << b->get_a() << endl;
    b->set_a(3);
}

void func_class_const_ref(unique_ptr<base> const& b)
{
    cout << __FUNCTION__ << b->get_a() << endl;
    b->set_a(4);
}


int main()
{
    unique_ptr<int> unique_p = make_unique<int>(0);
    // func_int(unique_p);
    // cout << "11. unique int " << *unique_p << endl;

    func_int_ref(ref(unique_p));
    cout << "12. unique int as ref"<< *unique_p << endl;

    func_int_ref_const(ref(unique_p));
    cout << "13. unique int as const ref"<< *unique_p << endl;

    unique_ptr<base> unique_base = make_unique<base>(base());
    unique_base->set_a(0);

    func_int_ref(move(unique_p));
    // cout << "14. unique int "<< *unique_p << endl; // cannot use

    // func_class(ref(unique_base));
    // cout << "21. unique int "<< unique_base->get_a() << endl;

    func_class_ref(ref(unique_base));
    cout << "22. unique int as ref "<< unique_base->get_a() << endl;

    func_class_ref_const(ref(unique_base));
    cout << "23. unique int as const ref "<< unique_base->get_a() << endl;

    func_class_const_ref(ref(unique_base));
    cout << "24. unique int as const ref "<< unique_base->get_a() << endl;

    return 0;
}