#include<iostream>
using namespace std;
//forward declaration
class complex;
class calculator{
    public:
    int addrealpart(complex,complex);
    int mul(int a,int b){
        return a*b;
    }
};
class complex{
    int a,b;
    public:
    void set_data(int x,int y){
        a=x;
        b=y;
    }
    //individual declaration of friend function
    friend int calculator::addrealpart(complex,complex);
    friend complex addcomplex(complex c1,complex c2);
    //declaring the whole class as friend
    friend class calculator;
    void show_data(){
        cout<<a<<" + i"<<b<<endl;
    }
};
int calculator  :: addrealpart(complaex c1,complex c2){
    return (c1.a+c2.a);
}
complex addcomplex(complex o1,complex o2){
    complex o3;
    o3.set_data((o1.a+o2.a),(o1.b+o2.b));
    return o3;
}
//properties of freind function
//1. not in the scope of class 
//2. since it is not in the scope of class, it cannot be called from the object of that class. c1.addcomplex() == invalid
//3. can be invoked without the help of any object
//4. usually contains the objects as arguments
//5. can be declared inside public or private section of the class
//6. it cannot access the members directly by their names and need object_name.member_name to access any member

int main()
{
    complex c1;
    c1.set_data(3,4);
    c1.show_data();
    complex c2;
    c2.set_data(5,6);
    c2.show_data();
    complex c3;
    c3=addcomplex(c1,c2);
    c3.show_data();
return 0;
}