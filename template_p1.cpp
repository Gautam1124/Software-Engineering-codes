#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Complex{
    float x,y;
    public:
    Complex(float x, float y): x(x) , y(y){
        cout<<"Ctor is called"<<endl;
    }
    bool operator>(Complex &a){
        return x*y > (a.x)*(a.y) ? 1 : 0; 
    }
    friend ostream& operator<<(ostream& os, Complex& a){
        os << "the value of x and y is ( "<<a.x<<" ,"<<a.y<<" )"<<endl;
    }
};




//Template function basics defination
template<class T>
T Max(T a, T b){
    return (a > b) ? a : b;
}
/* • The traits of type variable T include
default constructor (T::T()) and
copy assignment operator (T operator=(const T&) */



//Template Specialization for comparision C-style string
template<>
char* Max<char*>(char * x, char* y){
    cout<<"Specialized is called "<<endl;
    return strcmp(x,y)> 0 ? x : y;
}


template<class T>
bool Max(T a){                          //Overlaoding a template function is similar like overloading normal function but they can't overloaded with the data type because "T" is the auto data type it can overloaded with no. of argument passed. and also not with return type.
    cout<<"hello"<<endl;
}

template<class T, int size>         //overloading of a max template function. Takes two argument
T Max(T x[size]){                   // in place of T x[size]  :: T x[] can also be used as both are refering to the adress of a memory but T x[size] enables pointer to do bound checking.
    T ele = x[0];
    for(int i=0;i<size;i++){
        ele = max(ele,x[i]);
    }
    return ele;
}

//avoid implicit initialization of template
int main(){
    cout<<Max<int>(2,5)<<endl;
    cout<<Max<int>(7.5,5)<<endl;        //In this case imagine like the function takes two parameter of int type.
    char s[]="hello";
    char s1[]="world";
    cout<<Max<char*>(s, s1)<<endl;

    Complex c1(2,5);
    Complex c2(4,7);
    Complex x = Max<Complex>(c1,c2); 
    cout<<x;

    int arr[] = {1,2,3,4,5,5,6};
    cout<<Max<int, 7>(arr)<<endl;

}