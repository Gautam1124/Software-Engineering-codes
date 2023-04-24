#include<iostream>
#include<vector>
using namespace std;

template<class T = int>
class Stack{
    vector<T> data;
    int top;
    public:
    Stack(): top(-1){
        cout<<"Hello Stack is created"<<endl;
    }
    void push(T ele){
        data.push_back(ele);
        top++;
    }
    T pop(){
        T temp;
        temp = data[top];
        data.pop_back();
        top--;
        return temp;
    }
};

int main(){
    Stack<int> st;
    st.push(23);
    cout<<st.pop()<<endl;

    Stack<char> sc;
    sc.push('r');
    sc.push('t');
    cout<<sc.pop()<<endl;

    Stack<> si;
    si.push(2);
    si.push(6);
    cout<<si.pop();
}