#include<bits/stdc++.h>
using namespace std;

class LRUCACHE{
    public:
    class Node{
        public:
            int key,val;
            Node* prev;
            Node* next;
            Node(int k,int v){
                key=k;
                val=v;
                prev=next=NULL;
            }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*>m;
    int limit;
    LRUCACHE(int capacity){
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* newNode){//O(1)
        Node* oldnext=head->next;
        head->next=newNode;
        oldnext->prev=newNode;
        newNode->next=oldnext;
        newNode->prev=head;
    }
    void delNode(Node* oldNode){//O(1)
        oldNode->prev->next=oldNode->next;
        oldNode->next->prev=oldNode->prev;
    }
    void put(int key,int val){//O(1)
        if(m.find(key)!=m.end()){
            Node* oldNode=m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode=new Node(key,val);
        addNode(newNode);
        m[key]=newNode;
    }
    int get(int key){
        if(m.find(key)==m.end()){
            return -1;
        }
        int ans=m[key]->val;
        Node*ansNode=m[key];
        delNode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;
        return ans;
    }
};

