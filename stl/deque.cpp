#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int>dq={8,5,2,4,1};
    //It can be randomly access
    dq.push_front(10);
    dq.push_back(10);
    for(int i=0;i<dq.size();i++){
        cout<<dq[i]<<endl;
    }
}