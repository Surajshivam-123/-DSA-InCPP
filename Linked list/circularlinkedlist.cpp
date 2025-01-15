#include<iostream>
using namespace std;
class Node{
public:
      int data;
      Node* next;
      Node(int val){
        data=val;
        next=NULL;
      }
};
class CircularLinkedlist{
    Node* head;
    Node* tail;
public:
    CircularLinkedlist(){
        head=tail=NULL;
    }
    void insertAtHead(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            newNode->next=head;
        }
        else{
            newNode->next=head;
            tail->next=newNode;
            head=newNode;
            // OR(WITHOUT USING HEAD)
            // newNode->next=tail->next;
            // tail->next=newNode;
        }
    }
    void insertAtTail(int val){
        Node* newNode=new Node(val);
        if(tail==NULL){
            head=tail=newNode;
            tail->next=head;
        }
        else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
    }

    void deleteAtHead(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=head;
            tail->next=head->next;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void deleteAtTail(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
        }
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }
        else{
            Node* temp=tail;
            Node* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            
            prev->next=head;
            tail=prev;
            temp->next=NULL;
            delete temp;
        }
    }
    void print(){
        if(head==NULL)return;
        Node* temp=head;
        cout<<temp->data<<" ";
        temp=temp->next;
        while(temp!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    }
};
int main()
{
    CircularLinkedlist cl;
    cl.insertAtHead(1);
    cl.insertAtHead(2);
    cl.insertAtTail(3);
    cl.insertAtTail(4);
    cl.deleteAtHead();
    cl.deleteAtTail();
    cl.print();

return 0;
}