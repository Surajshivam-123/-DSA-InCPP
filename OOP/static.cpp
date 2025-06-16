#include<iostream>
using namespace std;
void fun(){
    int x=0;
    cout<<x<<endl;
    x++;
}
void fun1(){
    static int x=0;
    cout<<x<<endl;
    x++;
}


class A{
    public:
    static int count;
    A(){
        count++;
        cout<<"Constructor"<<endl;
    }
    ~A(){
        cout<<"Destructor"<<endl;
    }

    static void greet(){
        cout<<"Good Morning!"<<endl;
    }
    void f(){
        cout<<"Fun in A"<<endl;
    }
};

int A::count=0;

int main()
{
    fun();
    fun();
    fun();
    fun1();
    fun1();
    fun1();
    static A obj;
    A obj2;
    cout<<obj2.count<<endl;
    obj2.greet();
    A::greet();
    obj.f();
   // A::f();shows error
    cout<<"End of main"<<endl;
return 0;
}