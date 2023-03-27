#include <iostream>
using namespace std;

class B;
class A{
    int a;
    string str_;
    B* b;                //U can't create an object of the class before the defination of class, but u can create a pointer to that;
    /*A friend function can acesss have the private and other member of other classes it doesn't means that u can acess these without having an object of the class there should be an acessigng thorought objec*/
    public:
    A(){cout<<"Default ctor is called"<<endl;}
    A(int,string);
    



   /*it is not allowed=> A(int i=0,string str=""):a(i),str_(str){        
        cout<<"Modified constructor is called"<<endl;
    }  because it will create another signature of default constructor and lead ot ambiguity*/


    void print();
};
class B{
    int b;
    string str_;
    public:
    B(int i=0,string str=""):b(i),str_(str){
        cout<<"Modified constructor is called"<<endl;
    }
    // friend void A::print();  :: instead of doing this u can declare a frinend A here
    friend class A;
    //Both will work.
};

A::A(int i,string str_):a(i),str_(str_){                    //we declared after defination of B so that we can create an object of B;
        b = new B(i,str_);                  
        cout<<"Modified constructor is called"<<endl;
     }
void A::print(){
    cout<<"A::a =>"<<a<<endl;
    cout<<"A::str_ =>"<<str_<<endl;
    cout<<"B::b =>"<<b->b<<endl;
    cout<<"B::str_ =>"<<b->str_<<endl;   //B::str_ will not work because it is not heirarchy.
}

int main(){
    A a(5,"Hello");
    a.print();
    return 0;
}