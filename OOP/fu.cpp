#include<iostream>
#include<vector>
using namespace std;
class student{
    public:
    student(){
        cout<<"student constructor"<<endl;
    }
    ~student(){
        cout<<"student destructor"<<endl;
    }
};
class Person : public student{
    public:
    Person(){
        cout<<"person constructor"<<endl;
    }
    ~Person(){
        cout<<"person destructor"<<endl;
    }
};

int main()
{
    // Person p;
    vector<int>a={1,23,4};
    cout<<a.back()<<endl;
return 0;
}