#include<iostream>
using namespace std;
// Classes and Objects
// objects->entities in the real world
// classes->it is like a blueprint of these entities
// Ex->we form class which consist many functions regarding a particular topic

//Private class
class Teacher{
    //Properties/Attributes/Data
    string name;
    string dept;
    string subject;
    double salary;
    //Methods
    void change_dept(string newdept){
        newdept=dept;
    }
};
//Public class
class Teacherpub{
    public:
    //Properties/Attributes/Data
    string name;
    string dept;
    string subject;
    double salary;
    //Methods
    void change_dept(string newdept){
        newdept=dept;
    }
};
//Public and Private class
class student{
    private:
    string name;
    double mis;
    public:
    double roll;
    //Setter->we can set any value to private data through this 
    void setMis(double n){
        mis=n;
    }
    //Getter->we can get any value to private data through this 
    double getMis(){
        return mis;
    }
};
int main(){
    Teacher t2;//Objects
    // t2.name="Suraj";//We cannot write like this in private class it gives error
    // t2.subject="C++";
    // t2.dept="Ece";
    // t2.salary=45000;
    // cout<<t2.name<<endl;//Gives Error because by default all data is private inside class
    
    //ACCESS MODIEFIERS
    //private->data and methos are accessible inside class
    //public->data and methos are accessible to everyone
    //protected->data and methos are accessible inside class and its derived class
    
    Teacherpub t1;
    t1.name="Mohan";
    cout<<t1.name<<endl;//not give error because class is public

    student s1;
    // s1.name="Rohan";//Gives error
    s1.roll=1234;
    // cout<<s1.name<<" ";//Give error
    cout<<s1.roll<<endl;
    
    s1.setMis(112416068);
    cout<<s1.getMis()<<endl;

    //MAJOR TOPICS UNDER OOPS
    //1.ENCAPSULATION
    //2.ABSTRACTION
    //3.INHERITANCE
    //4.POLYMORPHISM

    //ENCAPSULATION->Wrapping up(Declartion) of data & member functions in a single unit
    //helps in data hiding

    