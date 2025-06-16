#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};
class doublelinkedlist{
    Node* head;
    Node* tail;
public:
    doublelinkedlist(){
        head=tail=NULL;
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;//
            newNode->prev=tail;
            tail=newNode;
        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            Node* temp=head;
            head=head->next;
            if(head!=NULL){
                head->prev=NULL;//backword connection is break
            }
            temp->next=NULL;//forward connection is break
            delete temp;
        }
    }
void pop_back(){
    if(head==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        Node* temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            tail->next=NULL;//forward connection is break
        }
        temp->prev=NULL;//backword connection is break
        delete temp;
    }
}
void getinfo(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
};
int main()
{
doublelinkedlist l;
    l.push_front(1);
    l.push_front(2);
    l.push_back(3);
    l.push_back(4);
    l.pop_front();
    l.pop_back();
    l.getinfo();
return 0;
}