#include<iostream>
#include<list>
using namespace std;
class Stack{
    list<int>ll;
public:
    void push(int val){
        ll.push_front(val);
    }
    int top(){
        return ll.front();
    }
    int pop(){
        int a=top();
        ll.pop_front();
        return a;
    }
    bool empty(){
        return ll.size()==0;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    if(s.empty())
        cout<<"Empty";
    else
        cout<<"Not Empty"<<endl;
return 0;
}