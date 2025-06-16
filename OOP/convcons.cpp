#include<iostream>
using namespace std;
//conversion of user defined to builtin using conversion operator
//conversion of builtin user defined to using conversion constructor
class Number{
    int x;
    int y;
    public:
    //conversion constructor to ocnvert int to Number(obj)
    Number(int v):x(v),y(0){
        // cout<<"conversion constructor"<<endl;
    }
    Number(int a,int b):x(a),y(b){}
    //conversion operator to convert Number(obj) to int
    operator int(){
        cout<<"conversion operator"<<endl;
        return x;
    }
    void display(){
        cout<<"value x: "<<x<<endl;
        cout<<"value y: "<<y<<endl;
    }
};
class A{
    int value;
    public:
    A(int v):value(v){}
    friend class B;
    void display(){
        cout<<"Value: "<<value<<endl;
    }
};
class B{
    int  data;
    public:
    B(){}
    B(A obj):data(obj.value){}//conversion constructor (user defined to user defined)
    void display(){
        cout<<"Data: "<<data<<endl;
    }
};

class D{
    int datad;
    public:
    D(int d):datad(d){}
    friend class C;
    void display(){
        cout<<"Datad: "<<datad<<endl;
    }
};
class C{
    int datac;
    public:
    C(int d):datac(d){}
    //user defined to user defined by using conversion operator
    operator D(){
        return D(datac);
    }
    void display(){
        cout<<"Datac: "<<datac<<endl;
    }
};
int main(){
    Number num1(45);
    int x=num1;
    cout<<x<<endl;
    int y=10;
    Number num2=y;
    num2.display();
    Number num3(67,34);
    num3.display();
    A a(5);
    a.display();
    B b;
    b=a;//calls conversion constructor
    b.display();
    C c(98);
    c.display();
    D d=c;//calls conversio operator
    d.display();
return 0;
}