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
    A(){
        cout<<"Constructor"<<endl;
    }
    ~A(){
        cout<<"Destructor"<<endl;
    }
};
int main()
{
    fun();
    fun();
    fun();
    fun1();
    fun1();
    fun1();
    static A obj;
    cout<<"End of main"<<endl;
return 0;
}