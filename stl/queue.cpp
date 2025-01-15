#include<iostream>
#include<queue>
using namespace std;
int main(){//First in first out
    queue<int>q;
    q.push(7);
    q.push(10);
    //front/ top+
    cout<<q.front()<<endl;
}