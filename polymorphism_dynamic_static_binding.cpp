#include<iostream>
using namespace std;

class B{
    protected:
    int i;
    string str;
    public:
    B(int i,string str_):i(i),str(str_){
        cout<<"constructor of base class is called"<<endl;
    }
    virtual void print(){                   //virtual function
        cout<<"Base class"<<endl;
        cout<<str<<"  "<<i<<endl;
    }
    void nacho(){
        cout<<"Nacho Nacho"<<endl;
    }

};
class D:public B{
    int j;
    public:
    D(int j,string str):j(j),B(j,str){
        cout<<"Derived class ctor"<<endl;
    }
    void print(){                            //virtual funciton.
        cout<<"Base class"<<endl;
        cout<<str<<"  "<<i<<endl;           //private attributes are not acessed so make it protected.
    }
    void nacho(){
        cout<<"Dance Dance"<<i<<endl;
    }
};

int main(){
    B b(4,"hello");
    D d(5,"Namaste");
    b.print();      //Dynamic binding virtual function are bind from virtual funciton table at runtime.
    d.print();      //same

    b.nacho();       //Static binding normal funciton 
    d.nacho();        //same.

    B* pb = &b;
    pb->print();
    pb->nacho();

    pb = &d;
    pb->print();        //dynamic binding the outcome of this function is decided by the type of object
    pb->nacho();        //static binding.

    D* pd;
    pd = static_cast<D*>(&b);   //typecasting the base class pointer into derived class pointer note that we can't type cast objects but can do with pointers and reference.
    pd->print();        //hello 4
    pd->nacho();        //Dance Dance 4
    //Typecasting a base class pointer in derived class pointer is not a good habbit but if u do and try to acess the datamember of base class it will be acessible.


    return 0;
}