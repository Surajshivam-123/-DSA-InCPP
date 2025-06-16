#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int main(){
    queue<int>q;
    q.push(5);
    q.push(10);
    q.push(9);
    q.pop();
    cout<<"Front :"<<q.front()<<endl;
    while(!q.empty()){
        cout<<q.front()<<"<-";
        q.pop();
    }
    cout<<endl;
    cout<<"IsEmpty :"<<q.empty()<<endl;
    //deque
    deque<int>dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);//1,2,3
    dq.push_front(4);//4,1,2,3
    dq.pop_back();//4,1,2
    dq.pop_front();//1,2
    cout<<"Front: "<<dq.front()<<endl;
    cout<<"Back: "<<dq.back()<<endl;
return 0;
}