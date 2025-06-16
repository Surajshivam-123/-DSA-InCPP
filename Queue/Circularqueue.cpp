#include<iostream>
using namespace std;
//push(1)->1
//push(2)->1,2
//push(3)->1,2,3
//pop()->    2,3
//push(4)->4,1,2
class CircularQueue{
public:
    int *a;
    int cap;
    int f,r;
    int currsize;
    CircularQueue(int size){
        cap=size;
        a=new int[cap];
        f=0;r=-1;
        currsize=0;
    }
    void push(int val){
        if(currsize==cap){
            cout<<"CQ is Full\n";
            return;
        }
        r=(r+1)%cap;
        a[r]=val;
        currsize++;
    }
    void pop(){
        if(currsize==0){
            cout<<"CQ is Empty\n";
            return;
        }
        f=(f+1)%cap;
        currsize--;
    }
    int front(){
        return a[f];
    }
    bool isEmpty(){
        return currsize==0;
    }
    void printArr(){
        for(int  i=0;i<cap;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    CircularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    cq.printArr();
    while(!cq.isEmpty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }
}