#include<iostream>
using namespace std;
class Base {
  public:
      Base(){cout<<"Base C"<<endl;}
     virtual ~Base() {}
  };
  class Derived : public Base {
     int* p;
  public:
     Derived() { p = new int[10]; }
     ~Derived() { delete[] p; std::cout << 
 "Derived Cleaned\n"; }
  };
  int main() {
     Base* b = new Derived;
     delete b;
     return 0;
  }
