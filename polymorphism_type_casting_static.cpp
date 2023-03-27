#include <iostream>
using namespace std;

class AB
{
public:
    string name;
    AB()
    {
        cout << "Abstract base class" << endl;
    }
    virtual void Krishna() = 0;
};
class D1 : public AB
{
public:
    string name = "Gopal";
    D1() { cout << "D1 is created" << endl; }
    void Krishna()
    {
        cout << "Hare Krishna" << endl;
    }
};
class D2 : public D1
{
public:
    D2()
    {
        cout << "D2 is created" << endl;
    }
    D2(const D1 &) { cout << "hello" << endl; } // Declared a constructor which can temporarily convert the object of D1 into D2, the temporary object of D2 will be created.
    void Krishna()
    {
        cout << "Hare Rama" << endl;
    }
};
int main()
{
    D1 d1;
    D2 d2;
    const D1 cd1;
    AB *pab;
    D1 *pd1;
    D2 *pd2;

    //*************const object
    // const_cast can't be used for type conversion.
    ((D1)cd1).Krishna(); // is allowed
    // const_cast<D1>(d1).Krishna() is not allowed const_cast only works for pointer and references

    const_cast<D1 &>(cd1).Krishna();   // conversion into reference is fine
    const_cast<D1 *>(&cd1)->Krishna(); // conversion into pointer is fine.

    //*************Static casting
    ((D1)d2).Krishna();            // explicit upcast valid
    static_cast<D1>(d2).Krishna(); // explicit upcast fine but not downcast
    d1.name = "Govind";
    cout << static_cast<D2>(d1).name; // no suitable user-defined conversion from "D1" to "D2" existsC/C++(312)

    pab = &d1;
    pab = &d2;
    pab = static_cast<AB *>(&d1);

    pd1 = &d1;
    pd1 = &d2;
    pd1 = static_cast<D1 *>(&d2);
    D1 &Rd1 = static_cast<D1 &>(d2);

    // pd2 = &d1;   (downcast is not allowed.)
    pd2 = static_cast<D2 *>(&d1);
    D2 &Rd2 = static_cast<D2 &>(d1);

    pd2->Krishna(); // Krishna is a virtual function.

    return 0;
}