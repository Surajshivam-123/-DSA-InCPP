#include<iostream>
using namespace std;

class Person{
protected:
    string name;
    int age;
public:
    Person(string n,int a):name(n),age(a){
        cout<<"Person Constructor called"<<endl;
    }
    void fun2(){
        cout<<"Person Fun is called"<<endl;
    }
};

class Faculty:virtual public Person{
protected:
    string empid;
    int salary;
public:
    Faculty(string n,int a,string e,int s):Person(n,a),empid(e),salary(s){
        cout<<"Faculty Constructor called"<<endl;
    }
    void fun3(){
        cout<<"Faculty Fun is called"<<endl;
    }
};

class Student:virtual private Person{
protected:
    string sid;
    int fee;
public:
    Student(string n,int a,string s,int f):Person(n,a),sid(s),fee(f){
        cout<<"Student Constructor called"<<endl;
    }
    void fun(){
        cout<<"Student Fun is called"<<endl;
    }
};

class TA:public Student,public Faculty{
protected:
    string course;
public:
    TA(string n,int a,string s,int f,string e,int sal):Person(n,a),Student(n,a,s,f),Faculty(n,a,e,sal){
        cout<<"TA constructor called"<<endl;
    }
    void fun1(){
        cout<<"TA Fun is called"<<endl;
    }
    void getname(){
        cout<<name<<endl;
    }
};

int main(){
    TA t("suraj",15,"s123",12000,"t123",10000);
    t.fun();
    t.getname();
}