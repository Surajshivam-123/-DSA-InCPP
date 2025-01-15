#include<iostream>
using namespace std;
//Node class to create a node
class Node{
public:
    int data;
    Node* nextptr;

    Node(int val){
        data=val;
        nextptr=NULL;
    }
};
//List class to create a linked list
class List{
    Node* head;
    Node* tail;

public:
    List(){
        head=tail=NULL;
    }
    //insert at the front of the linked list
    void push_front(int val){//O(1)
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }

        else{
            newNode->nextptr=head;
            head=newNode;
        }
    }
    //insert at the end of the linked list
    void push_back(int val){//O(1)
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
           tail->nextptr=newNode;
           tail=newNode;
        }
    }
    //delete the first element of the linked list
    void pop_front(){//O(1)
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            Node* temp=head;
            head=head->nextptr;
            temp->nextptr=NULL;
            delete temp;
        }
    }
    //delete the last element of the linked list
    void pop_back(){//O(n)
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node*temp=head;
            while(temp->nextptr!=tail){
                temp=temp->nextptr;
            }
            temp->nextptr=NULL;
        delete tail;
        tail=temp;
        }
        //insert at a given position
    void insert(int val,int pos){//O(n)
        if(pos==0){
            push_front(val);
            return;
        }
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->nextptr;
        }
        if(pos<0 && temp==NULL){
            cout<<"Invalid position"<<endl;
            return;
        }
        newNode->nextptr=temp->nextptr;
        temp->nextptr=newNode;
    }
    //search for a value in the linked list
    int search(int val){//O(n)
        Node*temp=head;
        int pos=0;
        while(temp!=NULL){
            if(temp->data==val){
                return pos;
            }
            pos++;
            temp = temp->nextptr;
        }
        return -1;
    }
    //print the linked list
    void printll(){//O(n)
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->nextptr;
        }
        delete temp;
}
int length(){
    int l=0;
    Node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->nextptr;
    }
    return l;
}
};
//Slow and fast pointer approach to find the middle of the linked list
Node* middle(Node* head){//TC->O(n/2)//SC->O(1)
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->nextptr!=NULL){
        slow=slow->nextptr;
        fast=fast->nextptr->nextptr;
    }
    return slow;
}


//detect a cycle in the linked list
//1.brute force approach
bool cycle1(Node *head) {//TC->O(n)//SC->O(n)
        unordered_set<Node*>s;
        Node* temp=head;
        while(temp!=NULL){
            if(s.find(temp)!=s.end()){
                return true;
            }
            s.insert(temp);
            temp=temp->nextptr;
        }
        return false;
    }
//2.slow and fast pointer approach
bool cycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->netptr!=NULL){
        slow=slow->netptr;
        fast=fast->netptr->nextptr;
        if(slow==fast){
            return true;
        }
    }
    return false;
}


//detect the starting point of the cycle

//using the brute force approach
Node *detectCycle(Node *head) {//TC->O(n)//SC->O(n)
        Node* ans=NULL;
        Node* temp=head;
        unordered_set<Node*>s;
        while(temp!=NULL){
            if(s.find(temp)!=s.end()){
                return temp;
            }
            s.insert(temp);
            temp=temp->nextptr;
        }
        return ans;
    }
//using the slow and fast pointer approach
Node* cyclestart(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->nextptr!=NULL){
        slow=slow->nextptr;
        fast=fast->nextptr->nextptr;
        if(slow==fast){
            break;
        }
    }
    if(fast!=NULL || fast->nextptr!=NULL){
        return NULL;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->nextptr;
        fast=fast->nextptr;
    }
    return slow;
}

//remove the cycle from the linked list
void removecycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->nextptr!=NULL){
        slow=slow->nextptr;
        fast=fast->nextptr->nextptr;
        if(slow==fast){
            break;
        }
    }
    if(fast!=NULL || fast->nextptr!=NULL){
        return NULL;
    }
    slow=head;
    Node* prev=NULL;
    while(slow!=fast){
        slow=slow->nextptr;
        prev=fast;
        fast=fast->nextptr;
    }
    prev->nextptr=NULL;
}
int main()
{
    List l1;
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    l1.push_back(4);
    l1.push_back(5);
    cout<<l1.length()<<endl;
//  l1.pop_front();
 // l1.pop_back();
 // l1.insert(6,1);
    l1.printll();
// //     cout<<l1.search(6)<<endl;
}