#include<iostream>
using namespace std;



int main(){
    //Implicit type conversion
    int i = 4;
    float f = 4.4;
    double d = 5.6667;
    i = d ;//(loss of data but no error)
    i = f;// same
    f = i; //promotion no loss of data safe
    f = d; // no loss of data
    d = i;  //same  
    d = f; //same

    int *pi = &i;
    // pi = &f;  (erorr) because can't be assigned between differet data types. IMPLICITLY
    //POinter of unrealated types can't be typecasted into one another
    pi = (int*)&f; //oKay 
    void * v = pi; //implict type cast into void is allowed


    int pstore = (int)pi; //(not  a good work still will get a warning because typecasting between different size is not suitable)
    long plstore = (long)pi;


    return 0;
}