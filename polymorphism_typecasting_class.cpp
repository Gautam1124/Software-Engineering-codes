#include <iostream>
using namespace std;
class A
{
    public:
    A() {}
};
class B
{
    public:
    B() {}
};

class Ar{
    public:
    Ar(){}
    

};

class Br:public Ar{
    public:
    Br(){}
};




int main()
{
    /*

    //*****Type casting of objects.
    A a;
    B b = a; //implicit type casting of unrelated classes are invalid.
    B be = (B)a; //Explicit type casting into unrelated classes are invalid.

    //******Type casting of pointers;
    B b1;
    B* pb = &b1;
    A* pa = &a;
//  pb = pa;        //implict type casting is invalid between pointers.
    pb = (B*)pa     //okay


    main crux is that implict binding happens at run time and explicit casting is a static binding so if the there is typecasting between different object and it is implicit it will give error but if it is explicit then still at static level casting between unrelated types is not possible
    For pointers implict casting if they are pointing different object then it will be error because it happens at r
    run time but at static binding both are pointer so they will be typecasted.

    */

   Ar ar;
   Br br;
   ar = br;     //Typecasting of derived class object in base class object is fine.
//    br = ar;        not allowed donwcasting implicitly
    // br = (Br)ar;         // Think of like unrelated class no suitable user-defined conversion from "Ar" to "Br" exists      u have to include a function of type operator Br(){cout<<"typecasted" return A()};
    // br = (Br)ar;
    Ar* arp = &ar;
    Br* brp = &br;
    arp = brp; //upcasting is allowed.
    brp = (Br*)arp ;//allowed explicitly



}