#include<iostream>
using namespace std;
//FIFO-First In First Out
class Node{
public:
    int data;
    Node* next;
    Node(){}
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class Queue{
public:
    Node *head;
    Node *tail;
    Queue(){
        head=tail=NULL;
    }
    void push(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    int pop(){//delete at front
        if(isempty())return -1;
        int ans=head->data;
        Node* temp=head;
        head=head->next;
        if(head==nullptr)tail=nullptr;
        delete temp;
        return ans;
    }
    int front(){
        if(isempty())return -1;
        return head->data;
    }
    // int rear(){
    //     if(isempty())return -1;
    //     Node* temp=head;
    //     while(temp->next!=nullptr){
    //         temp=temp->next;
    //     }
    //     return temp->data;
    // }
    bool isempty(){
        return head==nullptr;
    }
    void display(){
        Node* temp=head;
        while(temp->next!=nullptr){
            cout<<temp->data<<"<-";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};
int main(){
    Queue q;
    q.push(5);
    q.push(10);
    q.push(9);
    q.display();
    q.pop();
    q.display();
    cout<<"Front :"<<q.front()<<endl;
    // cout<<"Rear :"<<q.rear()<<endl;
    cout<<"IsEmpty :"<<q.isempty()<<endl;
return 0;
}