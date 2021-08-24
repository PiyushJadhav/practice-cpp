#include <iostream>

using namespace std;

class myException : public exception
{
    const char * what() const throw()
    {
        return "My exception.";
    }
};

enum myExceptions { A, B, C };

class myClass
{
    public:
    myClass()
    {
        cout << "myClass constructor." << endl;
    }
};

typedef struct
{
    int a;
}myStruct;

int main( int arg, char** argv )
{
    myStruct dummy_struct;

    try
    {
        cout << "Inside try block" << endl;
        
        switch( stoi(argv[1]) )
        {
            case 0:
            {
                myException a;
                cout << "Throwing exception type." << endl;
                throw a;
            }
            break;

            case 1:
            {
                cout << "Throwing int." << endl;
                throw 1;
            }
            break;

            case 2:
            {
                cout << "Throwing string." << endl;
                throw "Hey throwing a string.";
            }
            break;
            
            case 3:
            {
                cout << "Throwing dummy struct." << endl;
                throw dummy_struct;
            }
            break;

            case 4:
            {
                myClass dummy_myClass;
                cout << "Throwing dummy class." << endl;
                throw dummy_myClass;
            }

            case 5:
            {
                int a = 100;
                cout << "Throwing int * type." << endl;
                throw &a;
            }
            break;

            case 6:
            {
                cout << "Throwing bad alloc type." << endl;
                throw std::bad_alloc();
            }
            break;

            case 7:
            {
                int a[2];
                cout << "Throwing out of range." << endl;
                a[3] = 1; // out_of_range();
            }
            break;

            default:
            {
                cout << "Throwing default exception type." << endl;
                exception a;
                throw a;
            }
            break;
        }
    }
    catch( myExceptions a )
    {
        cout << "Caught myExpection type." << endl;
    }
    catch( exception& a )
    {
        cout << "Base exceptions type." << endl;
    }
    catch( int a )
    {
        cout << "Caught int type." << endl;
    }
    catch( int * a )
    {
        cout << "Caught int pointer type." << endl;
    }
    catch( const char * a )
    {
        cout << "Caught string type." << endl;
    }
    catch( myStruct a )
    {
         cout << "Caught myStruct type." << endl;
    }
    catch( myClass a )
    {
         cout << "Caught myClass type." << endl;
    }
    catch(...)
    {
        cout << "Unknown type" << endl;
    }

    cout << "Finally." << endl;

}