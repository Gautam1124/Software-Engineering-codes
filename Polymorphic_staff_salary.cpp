#include<iostream>
#include <vector>
using namespace std;

class Employee{
    public:
    virtual void salary() = 0;
    virtual ~Employee(){                //If u will not declare the destructor in the base class it will not be printed while deleting derived class.
        cout<<"Dtor:Employee"<<endl;
    }
};

class Engineer:public Employee{
    protected:
    string name;
    public:
    Engineer(){}
    Engineer(string name):name(name){
        cout<<"Engineer is created"<<endl;
    }
    void salary(){
        cout<<"Salary::Engineer"<<endl;
    }
    ~Engineer(){
        cout<<"Engineer::Dtor is called"<<endl;
    }
    friend void Check(Engineer& e){
        cout<<e.name;
    }
};
class Manager:public Engineer{
    vector<Engineer*> reports;
    public:
    Manager(){cout<<"Manager is created"<<endl;}
    Manager(vector<Engineer*> vec,string name="ab"):reports(vec){
        cout<<"Manager is created"<<endl;
    }
    ~Manager(){
        cout<<"Dtor::manager is called"<<endl;
    }
    void salary(){
        cout<<"Salary::Manager"<<endl;
    }
};
class Director:public Manager{
    vector<Manager*> reports;
    public:
    Director(){cout<<"Director is created"<<endl;}
    Director(vector<Manager*> vec):reports(vec){
        cout<<"Director is created"<<endl;
    }
    ~Director(){
        cout<<"Direcotor::Dtor is called"<<endl;
    }
    void salary(){
        cout<<"Salary::Director"<<endl;
    }
};

class Saleserice:public Employee{
    string name;
    public:
    Saleserice(string name):name(name){
        cout<<"Salesevice object is created"<<endl;
    }
    ~Saleserice()
    {
        cout<<"saleservice::Dtor is called";
    }
    void salary(){
        cout<<"Salary::Saleservice"<<endl;
    }

};
int main(){
    Employee * all_employee[] = {new Engineer("Gopal"),new Manager,new Director(),new Saleserice("Krishna")};       //This is a array of pointers means 2-D array;
    cout<<endl;
    for(int i=0;i<sizeof(all_employee)/sizeof(Employee*);i++){      //sizeof(all_employee) will give the total bit size of array but we need no. of element so dividing it by the per block size.
        all_employee[i]->salary();
    }
    cout<<endl;
    for(int i=0;i<sizeof(all_employee)/sizeof(Employee*);i++){
        Employee* ptr;
        ptr = all_employee[i];
        delete ptr;
    }
    // delete [][] all_employee;
}