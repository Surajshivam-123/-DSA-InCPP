#include<iostream>
using namespace std;
void fun2(){
    int a=10;//This is stack memory — it’s automatically destroyed when the function ends.
    int *b=new int(20);//This allocates memory on the heap, which is not destroyed when the function ends. It stays there until you explicitly delete it using delete.
}

class ABC{
    public:
    int fun(int a,int b){
        return a+b;
    }
};
int (ABC::*funptr)(int, int)=ABC::fun;//without & is valid
int (ABC::*funptr3)(int, int)=&ABC::fun;//valid without brackets
//int (ABC::*funptr4)(int, int)=&(ABC::fun);//error: lvalue required as unary '&' operand
//int (ABC::*funptr2)(int, int);error: 'funptr2' does not name a type
//funptr2=&(ABC::fun);
int main()
{
    ABC a;
    cout<<(a.*funptr)(5,6)<<endl;
    fun2();
return 0;
}