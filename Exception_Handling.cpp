#include <iostream>
using namespace std;

class A{
    static int count;
    public:
    A(){
        count++;
        cout<<count<<" Object is constructed"<<endl;
        if(count>=4){
            throw count;
        }
    }
    ~A(){
        count--;
        cout<<count<<" Object is destructed"<<endl;
    }
};
int A::count =0;

int main(){
    try{
        A array[5];
        cout<<"After 5 allocation";
    }
    catch(int a){
        cout<<"Error after creating "<<a<<" block of memory"<<endl;
    }
    return 0;
}