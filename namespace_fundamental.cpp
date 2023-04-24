#include <iostream>
using namespace std; // we are bringing all the functionality of std namespace into this program as a gloabal scope.





// Namespace is like a home in a city
namespace myNameSpace
{
    int i;
    string str_;            //these act as a gloabal variable for the everything which is in thethis namespace str_ can be used by print();
    void print(int i, string str)
    {
        cout << "i::" << i << endl;
        cout << "str_::" <<str<< endl;
        cout << "global inside the namespace str_::" <<str_<< endl;
    }
    class A
    {
        int i;
        string str_;

    public:
        A(int i = 0, string str_ = "") : i(i), str_(str_)
        {
            cout << "A::ctor is called" << endl;
        }
        friend ostream &operator<<(ostream &os, A &a);
        A operator+(const A &);
    };
    ostream &operator<<(ostream &os, A &a)
    {
        os << a.i << endl;
        os << a.str_ << endl;
        return os;
    }

    // overloading as a member funciton
    A A::operator+(const A &a)
    {
        A ret;
        ret.i = i + a.i;
        ret.str_ = str_ + a.str_;
        return ret;
    }
} // namespace myNameSpace

namespace space1{
    using namespace space2;     //after doing this we can do space1::j in the main.
    namespace space2{
        int j;
    }
}



//this function is globally declared so it can be accessed in main 
void print(int j,string str){
    cout<<"just checking the ambiguity"<<endl;
}





int main(){
    // print(4,"hello"); this will give error because print is not in the global namespace to acess print use
    myNameSpace::print(4,"hello");
    myNameSpace::str_= "HI:>";

    // if we don't want to write myNameSpace::str_= "HI:>"; we can bring all the functionality fo tht namespace into main;
    using namespace myNameSpace;
    str_ = "Bonjor";
    // print(4,"Namaste");  doing this lead to ambiguity;

    using myNameSpace::print;   //It resolves the ambiguity as it instruct the compiler to use that print() which is declared in namespace myNameSpace.
    print(4,"namaste"); 
    ::print(6,"Gopal") // this will let u call the global print() function




    space1::j=4;
    using namespace space1;
    j=6;
    
}
