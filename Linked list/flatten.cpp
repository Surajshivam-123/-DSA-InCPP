#include<iostream>
using namespace std;
//Flatten a Multilevel Doubly Linked list
// How the multilevel linked list is represented in test cases:

// We use the multilevel linked list from Example 1 above:

//  1---2---3---4---5---6--NULL
//          |
//          7---8---9---10--NULL
//              |
//              11--12--NULL
// The serialization of each level is as follows:

// [1,2,3,4,5,6,null]
// [7,8,9,10,null]
// [11,12,null]
// To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

// [1,    2,    3, 4, 5, 6, null]
//              |
// [null, null, 7,    8, 9, 10, null]
//                    |
// [            null, 11, 12, null]
// Merging the serialization of each level and removing trailing nulls we obtain:

// [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
//Using recursion
Node* flatten(Node* head){//TC-O(n)//SC-O(n)
    if(head==NULL){
        return head;
    }
    Node* curr=head;
    while(curr!=NULL){
        if(curr->child!=NULL){
            //flatten the child notes
            Node* currnext=curr->next;
            curr->next=flatten(curr->child);
            curr->next->prev=curr;
            curr->child=NULL;
            //find tail
            while(curr->next!=NULL){
                curr=curr->next;
            }
            curr->next=currnext;
            if(currnext!=NULL){
                currnext->prev=curr;
            }
        }
        curr=curr->next;
    }
    return head;
}
int main(){
return 0;
}
