#include <bits/stdc++.h>
using namespace std;

// C++ Exception Class Hierarchy
// std::exception
// │
// ├── std::logic_error
// │   ├── std::invalid_argument
// │   ├── std::domain_error
// │   ├── std::length_error
// │   └── std::out_of_range
// │
// ├── std::runtime_error
// │   ├── std::range_error
// │   ├── std::overflow_error
// │   └── std::underflow_error
// │
// ├── std::bad_alloc
// ├── std::bad_cast
// ├── std::bad_typeid
// ├── std::bad_exception
// ├── std::bad_function_call
// └── std::ios_base::failure

class Parent{
    public:
    virtual void error()noexcept(false){
        cout<<"In Parent \n";
        throw logic_error("Logic Error");
    }
};
class Child:public Parent{
    public:
    void error()noexcept(false){
        cout<<"In Child \n";
        throw invalid_argument("Invalid_argument");
    }
};
class Client{
    Parent *p;
    public:
    Client(Parent *p){
        this->p=p;
    }
    void showError(){
        try
        {
            cout<<"Executing\n";
            p->error();
        }
        catch(logic_error& e)
        {
            cout << "Error"<<" "<<e.what() << '\n';
        }
    }
};
int main() {
    Client *c=new Client(new Child());
    c->showError();
    
    return 0;
}