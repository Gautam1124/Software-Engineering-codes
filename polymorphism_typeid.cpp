#include <iostream>
#include <typeinfo>
// #include <cxxabi.h>

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

int main(){
     A a(4,"Hari");
    B b(6,5,"Gopal");
    Ap ap(7,"Krishna");
    Bp bp(9,10,"Govind");

    A* pa = &a;
    A& ra = a;
    B& rb = b;
    B* pb = &b;
    Ap* pap = &ap;
    Bp* pbp = &bp;
    Ap& pra= ap;
    Bp& prb= bp;

    pa = &a; pb = &b ; pap = &ap ; pbp = &bp;
    cout<<typeid(pa).name()<<" "<<typeid(pb).name()<<" "<<typeid(pap).name()<<" "<<typeid(pbp).name()<<" "<<typeid(ra).name()<<" "<<typeid(rb).name()<<endl;
    cout<<typeid(*pa).name()<<" "<<typeid(*pb).name()<<" "<<typeid(*pap).name()<<" "<<typeid(*pbp).name()<<endl;

    pb = static_cast<B*>(&a);
    pbp = static_cast<Bp*>(&ap);
    cout<<typeid(pb).name()<<" "<<typeid(pbp).name()<<endl;
    

}