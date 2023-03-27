#include <iostream>
using namespace std;

class A{
    int i;
    string str_;
    public:
    A(int i=0,string str_=""):i(i),str_(str_){
        cout<<"A::ctor is called"<<endl;
    }
    friend ostream& operator<<(ostream &os,A& a);
    A operator+(const A&);
};

//overloading as a friend fucntion
ostream& operator<<(ostream &os,A& a){
    os<<a.i<<endl;
    os<<a.str_<<endl;
    return os;
}


//overloading as a member funciton
A A::operator+(const A& a){
    A ret;
    ret.i = i + a.i;
    ret.str_ = str_ + a.str_;
    return ret;
}

//overloading using gloabal fucntion(break the encapsulation as private data member are not acessed)
/*
A operator-(const A& a,const A& b){
    A ret;
    ret.i = a.i - b.i;
    ret.str_ = a.str_ + b.str_;
    return ret;
}


*/

int main(){
    A a(4,"Hello");
    A a2(8,"Gautam");
    A a3 = a + a2;
    cout<<a3;


}