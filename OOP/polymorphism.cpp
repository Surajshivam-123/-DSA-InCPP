#include<iostream>
using namespace std;
//POLYMORPHISM->ability of objects to take on different forms or behave in different ways depending on the context in which they are used.
//1.Compile time polymorphism(example->constructor overloading,function overloading)

//2.Run time polymorphism(example->function overriding,virtual functions)
//Function overloading->Parent and child both contain the same function with different implementation. The parent class function is said to be overridden.
//Virtual functions
//1.it is dynamic in nature
//2.defined by the word "virtual" inside a base class and are always with a parent class and overridden in child class.
//3.it is called during runtime

class person{
public:
    string name;
    person(){
        cout<<"non-parametrized  constructor"<<endl;
    }

    person(string name){//constructor overloading
    cout<<"parametrized constructor"<<endl;
}
    void print(int x){
        cout<<"int x="<<x<<endl;
    }
    void print(char x){//function overloading
        cout<<"char x="<<x<<endl;
    }
};
class parent{
public:
    void print(){
        cout<<"parent"<<endl;
    }
    virtual void wirte(){//virtual function
        cout<<"parent write"<<endl;
    }
};
class child:public parent{
public:
    void print(){//function overriding
        cout<<"child"<<endl;
    }
    void write(){
        cout<<"child write"<<endl;
    }
};
int main()
{
    person p1;//constructor overloading
    person p2("John");
    p1.print(10);//function overloading
    p1.print('a');
    parent p;
    child c;
    p.print();
    c.print();//child function overrides parent function
    p.wirte();
    c.write();//child function overrides parent function

return 0;
}