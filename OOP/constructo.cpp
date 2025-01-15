#include<iostream>
using namespace std;
//CONSTRUCTOR
    // -same name as class 
    // -constructor does not have a return type
    // ->Only called once(automatically) at object creation
    // ->memory allocation happens to objects when constructor is called
    //->always declared in public

    //Three types
    //Non Parametrized constructor
    //Parametrized constructor
    //copy constructor
class Teacher{
private:
    double salary;
public:
    string name;
    string dept;
    string subject;

    //Non Parametrized constructor
    Teacher(){
        dept="computer science";//default properites whenever constructor is called given value is set to object
        cout<<"hi i m constructor"<<endl;
    }
    //Parametrized constructor
    Teacher(string name,string dept,string s){
        this->name=name;
        (*this).dept=dept;
        subject=s;
    }
    //Copy constructor
    Teacher(Teacher &orgObj){
        cout<<"i m custom copy constructor";
        this->name=orgObj.name;
        this->dept=orgObj.dept;
        this->subject=orgObj.subject;
        this->salary=orgObj.salary;
    }
    void getInfo(){
        cout<<"name:"<<name<<endl;
        cout<<"subject:"<<subject<<endl;
    }
};
// More than one constructor can be made ->Constructor overloading it is an ex of polymorphism 
int main(){
    // Teacher t1;//constructor call
    // cout<<t1.dept<<endl;
    Teacher t2("Suraj","'ece'","computer");
    // t2.getInfo();
    cout<<t2.name<<endl<<t2.dept<<endl<<t2.subject<<endl;

    Teacher t3(t2);//default copy constructor
    t3.getInfo();

    Teacher t4(t3);//custom copy constructor
    t4.getInfo();


}
