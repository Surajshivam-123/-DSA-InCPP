#include<iostream>
using namespace std;
//INHERITANCE->When properties & member functions of base class are passed on to the derived class.
class person{
public:
    string name;
    int age;
    person(){
        cout<<"parent constructor"<<endl;//executes first
    }
    person(string name,int age){
        this->name=name;
        this->age=age;
    }
    ~person(){
        cout<<"parent destructor"<<endl;//executes last
    }
    void pinfo(){
        cout<<name<<" "<<age<<endl;
    }
};
 
class student:public person{//inheritance of all properties of person into student
public:
    int roll;
    student(){//executes last
        cout<<"child constructor"<<endl;
    }
    student(string name,int age,int roll):person(name,age){
        this->roll=roll;
    }
    ~student(){//executes first
        cout<<"child destructor"<<endl;
    }
    void info(){
        cout<<name<<" "<<age<<" "<<roll<<endl;
    }

};
//Modes of inheritance
//             Derived class   Derived class     Derived class 
// Parent classPrivate mode    Protected mode    Public mode
// Private     not inherited   not inherited     not inherited
// protected   Private         protected         protected
// public      private         protected         public

// Types of inheritance
// 1.single inheritance(Person->student)
// 2.multi-level inheritance(Person->student->gradStudent)
// 3.multiple inheritance(Person->student)
                        // |->teacher
// 4.hierarchical inheritance(teacher->headteacher,director)
// 5.hybrid inheritance(min 2 types of inheritance)


class gradStudent : public student{//multi-level inheritance
public:
    int dob;
};
class staff{
public:
    int sal;
    staff(){
        cout<<"staff constructotr"<<endl;
    }
    ~staff(){
        cout<<"staff destructotr"<<endl;
    }
};
class teacher :public person, public staff{//multiple inheritance
public:
    teacher(){
        cout<<"teacher constructotr"<<endl;
    }
    ~teacher(){
        cout<<"teacher destructotr"<<endl;
    }
};
class headTeacher : public teacher{//hierarchical inheritance

};
class director : public teacher{//hierarchical inheritance

};
int main()
{
    int i;
    cin>>i
    student s1;
    s1.name="Dholu";
    s1.age=12;
    s1.roll=68;
    s1.info();
    s1.pinfo();
    teacher t1;
    t1.name="Suraj";
    t1.sal=68;
    cout<<t1.name<<" "<<t1.sal<<endl;
    return 0;
}