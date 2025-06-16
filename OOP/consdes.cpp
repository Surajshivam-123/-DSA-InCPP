#include<iostream>
using namespace std;
class number{
    static int n;
    public:
    number(){
        cout<<"constructor number "<<++n<<" is called.\n";
    }
    ~number(){
        cout<<"destructor number "<<n--<<" is called.\n";
    }
    void d();
};
int number::n=0;
void number::d(){
    cout<<"friend function "<<n<<endl;
}
int main(){
    number a;
    a.d();
return 0;
}