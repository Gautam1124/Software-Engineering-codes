#include <iostream>
using namespace std;


class B{
    protected:
    int i;
    public:
    B(int i=0):i(i){
        cout<<"B is constructed=>"<<i<<endl;
    }
    ~B(){
        cout<<"B is Destructed"<<endl;
    }

};

class B1: virtual public B{
    protected:
    int i;
    string name;
    public:
    B1(int i=0,string name = ""):i(i),name(name),B(i){
        cout<<"B1 is constructed"<<endl;
    }
    ~B1(){
        cout<<"B1 is destructed"<<endl;
    }
    void print(){
        cout<<"Hare Krishna"<<endl;
    }
};
class B2:virtual public B{
    protected:
    int j;
    string name;
    public:
    B2(int j=0,string name =""):j(j),name(name),B(i){
        cout<<"B2 is constructed"<<endl;
    }
    ~B2(){
        cout<<"B2 is destructed "<<endl;
    }
    void print(){
        cout<<"Hare Rama"<<endl;
    }
};

class D:public B2,public B1{
    public:
    D(int j,string name):B2(j,name),B1(j,name),B(j){     //Instance of D is declared by D so if we haven't initialized in the list there must be default constructor for B.
        cout<<"D is constructed"<<endl;
    }
    ~D(){
        cout<<"D is destructed"<<endl;
    }
    using B1::print;
};

int main(){
    D d(4,"hari");
    d.print();
    return 0;
}


