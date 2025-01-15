#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s1;
    stack<int>s2;
    s1.push(4);
    s1.push(3);
    s2.push(6);
    s2.push(5);
    s1.swap(s2);
    //we can access only top element
    //front+ top/
    // cout<<s1.front()<<endl;
    cout<<s2.top()<<endl;
}