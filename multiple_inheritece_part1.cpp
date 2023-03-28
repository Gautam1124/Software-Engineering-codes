#include <iostream>
using namespace std;

class B1{
    protected:
    int i;
    string name;
    public:
    B1(int i=0,string name = ""):i(i),name(name){
        cout<<"B1 is constructed"<<endl;
    }
    ~B1(){
        cout<<"B1 is destructed"<<endl;
    }
    void print(){
        cout<<"Hare Krishna"<<endl;
    }
};
class B2{
    protected:
    int j;
    string name;
    public:
    B2(int j=0,string name =""):j(j),name(name){
        cout<<"B2 is constructed"<<endl;
    }
    ~B2(){
        cout<<"B2 is destructed "<<endl;
    }
    void print(){
        cout<<"Hare Rama"<<endl;
    }
};

class D:public B1,public B2{
    public:
    D(int j,string name):B2(j,name),B1(j,name){
        cout<<"D is constructed"<<endl;
    }
    ~D(){
        cout<<"D is destructed"<<endl;
    }

    using B1::name; // After this doing cout<<name will be fine.
    void gopal(){
        // cout<<name<<endl;        Lead to ambigous behaviour
      //  cout<<B1::name<<endl;   //fine
      cout<<name<<endl; //After using B1::name;
    }
};


int main(){
    D d(4,"Govind");
    d.gopal();


    return 0;
}