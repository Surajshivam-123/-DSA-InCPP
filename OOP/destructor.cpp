#include<iostream>
using namespace std;
class Student{
    public:
    Student(){//executes first
        cout<<"i m constructor\n";
    }
    ~Student(){//executes last
        cout<<"i m destructor\n";
        // delete anyptr;->used to deallocate memory
    }
};
int main(){
    Student s1;
}