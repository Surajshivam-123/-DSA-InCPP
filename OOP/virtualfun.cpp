#include<iostream>
using namespace std;

class BaseClass{
    public:
        int var_base=1;
        virtual void display(){
            cout<<"1 Dispalying Base class variable var_base "<<var_base<<endl;
        }
        void show(){
            cout<<"Show in base"<<endl;
        }
};

class DerivedClass: public BaseClass{
    public:
            int var_derived=2;
            // void display(){
            //     cout<<"2 Dispalying Base class variable var_base "<<var_base<<endl;
            //     cout<<"2 Dispalying Derived class variable var_derived "<<var_derived<<endl;
            // }
            void show(){
                cout<<"Show in derived"<<endl;
            }
};
int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    obj_base.display();
    base_class_pointer = &obj_derived;
    base_class_pointer->display();
    base_class_pointer->show();
    return 0;
}
// Rules for virtual functions
// 1.They cannot be static
// 2.They are accessed by object pointers
// 3.Virtual functions can be a friend of another class
// 4.A virtual function in the base class might not be used.
// 5.If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class