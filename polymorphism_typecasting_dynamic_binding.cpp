#include <iostream>
using namespace std;

class A{
    protected:
    int i;
    string name;
    public:
    A(int i,string name):i(i),name(name){
        cout<<"A is created"<<endl;
    }

};
class B:public A{
    int j;
    public:
    B(int i,int j=0,string name=""):A(i,name),j(j){
        cout<<"B is created"<<endl;
    }
};
class Ap{
    protected:
    int i;
    string name;
    public:
    Ap(int i,string name):i(i),name(name){
        cout<<"Ap is created"<<endl;
    }
    virtual void print(){
        cout<<"Radhe Radhe"<<endl;
    }

};
class Bp:public Ap{
    int j;
    public:
    Bp(int i,int j=0,string name=""):Ap(i,name),j(j){
        cout<<"Bp is created"<<endl;
    }
    void print(){
        cout<<"Hare Krishna"<<endl;
    }
};
//dynamic casting doesn't works on non polymorphic classes if we have a base class which is not polymorphic and we assign a base class pointer to derived class object and typecast it int derived class pointer it will be error because ther is no virtual table.
int main(){
    A a(4,"Hari");
    B b(6,5,"Gopal");
    Ap ap(7,"Krishna");
    Bp bp(9,10,"Govind");

    A* pa;
    B* pb;
    Ap* pap;
    Bp* pbp;
    void * v;
     //UPcast
    pa = &a;   
    pa = &b;
    pa = dynamic_cast<A*>(&b);

    pap = &ap;   
    pap = &bp;

    pa = &b;
    pb = &b;
    pb = static_cast<B*>(pa);
    // pb = dynamic_cast<B*>(pa); the operand of a runtime dynamic_cast must have a polymorphic class typeC
    pb = &b;
    pa = &a;
    pb = dynamic_cast<B*>(pb); // the pointer is same as it is typecasted no error


    //polymorphic functions.
    pap = &bp;
    // pbp = &ap; implict is not allowed
    pbp = static_cast<Bp*>(&ap);
    // pbp = dynamic_cast<Bp*>(&ap); *************this can never be done because dynamic casting is done on the basis of the object type if the object type the pointer is pointing is same then it will do the typecasting
    pbp = dynamic_cast<Bp*>(pap);// It will be fine because the object pap is pointing is of pB type.
    v = dynamic_cast<void*>(pap);
    // pap = dynamic_cast<Ap*>(v); cast from void* to any pointer is not allowed
    int *a = 0;
    // pa = dynamic_cast<A*>(a);



       


}


