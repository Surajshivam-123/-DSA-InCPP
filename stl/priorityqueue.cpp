#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    pq.push(8);
    pq.push(4);
    pq.push(5);
    //front+ top/
    //Descending order
    while(!pq.empty()){
        cout<<pq.top();
        pq.pop();
    }
    cout<<endl;
    //Ascending order
    priority_queue<int,vector<int>,greater<int>>pq1;
    pq1.push(8);
    pq1.push(4);
    pq1.push(5);
    while(!pq1.empty()){
        cout<<pq1.top();
        pq1.pop();
    }
}