#include<iostream>
using namespace std;
//SHALLOW COPY
//A shallow copy of an object copies all of the member values from one object to another

//DEEP COPY
//A deep copy , on the other hand , not only copies the member values but also makes copies of any dynamically allocated memory thst the members point to
class Student{
    public:
    string name;
    double* cgPtr;
    Student(string name,double cgpa){
        this->name=name;
        cgPtr=new double;
        *cgPtr=cgpa;
    }

    // Student(Student &obj){//shallow copy
    //     name=obj.name;
    //     cgPtr=obj.cgPtr;
    // }
    Student(Student &obj){//deep copy
        name=obj.name;
        cgPtr=new double;
        *cgPtr=*obj.cgPtr;
    }
    void getInfo(){
        cout<<name<<" "<<*cgPtr<<endl;
    }
};
int main(){
    Student s1("sohan",8.9);
    // s1.getInfo();
    // Student s2(s1);//Shallow copy
    // s2.name="rohan";
    // *(s2.cgPtr)=9.2;
    // s1.getInfo();
    //here cgpa of s1 also changes->Limitation of shallow deep
    //Both copies share same memory address
     s1.getInfo();
    Student s2(s1);//deep copy
    s2.name="rohan";
    *(s2.cgPtr)=9.2;
    s1.getInfo();
    s2.getInfo();
}