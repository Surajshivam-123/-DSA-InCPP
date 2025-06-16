#include<iostream>
#include<vector>
using namespace std;
//Using arrays/vectors
class Stack{
    vector<int>s;
public:
    void push(int val){
        s.push_back(val);
    }
    int pop(){
       int a=s[s.size()-1];
       s.pop_back();
       return a;
    }
    int top(){
        return s[s.size()-1];
    }
    bool empty(){
        return s.size()==0;
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