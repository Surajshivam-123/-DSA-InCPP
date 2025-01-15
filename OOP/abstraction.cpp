#include<iostream>
using namespace std;
//Abstraction is the concept of hiding all unnecessary details and showing the important parts.
//example->using of private,public,protected in class
//USING OF ABSTRACT CLASS  
//1.Abstract class are used to provide a base class from which other classes can be derived.
//2.Abstract class cannot be used to instantiate objects and are ment to be inherited.
//3.Abstract classes are typically used to defined an interface for derived classes.

class Animal{//abstract class
    virtual void sound()=0;//pure virtual function
public:
      string name;
      int age;

};
class Dog:public Animal{
    public:
    void sound(){
        cout<<"Dog barks"<<endl;
    }
};
int main()
{
    // Animal a;//shows error because we cannot create object of abstract class
    Dog d;
    d.sound();
    d.name="Tommy";
    cout<<d.name<<endl;
return 0;
}
