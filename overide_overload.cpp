#include<iostream>
using namespace std;

class B{
    int i;
    string str;
    public:
    B(int i=0,string str=""):i(i),str(str){
        cout<<"Constructor of B is called"<<endl;
    }
    void print(){
        cout<<"Check 1"<<endl;
    }

};

class D:public B{
    int j;
    string strd;
    public:
    D(int j,string str):j(j),strd(str),B(j,str){
        cout<<"Cosntructor of D is called"<<endl;
    }
    void print(){
        B::print();
        cout<<"Check 2"<<endl;
    }
    //using B::print; this will not overshadow the original print( funciton.
};

int main(){
    D d(3,"Krishna");
    d.print();
    return 0;
}