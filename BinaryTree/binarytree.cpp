#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

/*TREE-Heirarchial data structure
  It includes node and root.
  Terms:-
    LeafNodes-Node which has no child
    Sibling-Adjacent Nodes
    Left subtree,Right Sub tree
    Height of tree=Levels of tree

    Binary Tree-At max 2 child of each node.

    Building of binary tree
            1
        2       3
   null null  null  null
   preorder sequence(ps)
   null=-1
   Process-start from root and then left subtree snd then right sub tree
   [1,2,-1,-1,3,-1,-1]

   EX:-if ps=[1,2,-1,-1,3,4,-1,-1,5,-1,-1]
   Binary tree of given ps is
                            1
                    2                       3
            -1              -1       4             5
                                  -1    -1      -1    -1
    */

class Node{
    public:
    int data;
    Node* left;//store address of left child
    Node* right;//store address of right child
    Node(int d){
        data=d;
        left=right=nullptr;
    }
};
int idx=-1;
Node* buildBintree(vector<int>preorder_seq){//TC-O(n)
    idx++;
    if(preorder_seq[idx]==-1)
        return nullptr;
    Node* root=new Node(preorder_seq[idx]);
    root->left=buildBintree(preorder_seq);
    root->right=buildBintree(preorder_seq);
    return root;
}

//Four major alogorithms for traversal
//Recursion
//1.Preorder
//2.Inorder
//3.Postorder
//Iterative
//4.Levelorder

//1.Predrder traversal(start from top then left and then right)
void Preorder_traversal(Node* root){//TC->O(n)
    if(root==nullptr){
        cout<<-1<<" ";
        return;
    }
    cout<<root->data<<" ";
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
}

//2.Inorder traversal(start from left and then top and then right)
void Inorder_traversal(Node* root){//TC->O(n)
    if(root==nullptr){
        cout<<-1<<" ";
        return;
    }
    Inorder_traversal(root->left);
    cout<<root->data<<" ";
    Inorder_traversal(root->right);
}

//PostOrder Traversal(start from leftand then right)
void Postorder_traversal(Node* root){//TC->O(n)
    if(root==nullptr){
        cout<<-1<<" ";
        return;
    }
    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    cout<<root->data<<" ";
}

//LevelOrder Traversal(traverse levels  from left to right and top to bottom )
void LevelOrder_traversal(Node* root){//TC->O(n)
    queue<Node*>q;
    q.push(root);
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
        if(curr==nullptr){
            cout<<-1<<" ";
        }
        else{
            cout<<curr->data<<" ";
        }
        if(curr!=nullptr)
            q.push(curr->left);
        if(curr!=nullptr)
            q.push(curr->right);
    }

}
//Each level in different line
void LevelOrder_traversal2(Node* root){//TC->O(n)
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
        if(curr==nullptr){
            if(!q.empty()){ 
                cout<<endl;
                q.push(nullptr);
                continue;
                }
            else{
                break;
            }
        }
        else{
            cout<<curr->data<<" ";
        }
        if(curr->left!=nullptr)
            q.push(curr->left);
        if(curr->right!=nullptr)
            q.push(curr->right);
    }

}


int height(Node* root){//TC->O(N)
    if(root==nullptr)return 0;
    int lefth=height(root->left);
    int righth=height(root->right);
    return max(lefth,righth)+1;
}

int countTotalNodes(Node* root){//TC->O(N)
    if(root==nullptr)return 0;
    int leftc=countTotalNodes(root->left);
    int rightc=countTotalNodes(root->right);
    return 1+leftc+rightc;
}

int NodeSum(Node* root){
    if(root==nullptr)return 0;
    int lefts=NodeSum(root->left);
    int rights=NodeSum(root->right);
    return lefts +rights+root->data;
}

//to find diameter of binary (longest distance between two leaf nodes)
int height(Node* root,int &n){//TC->O(n)
    if(root==nullptr){
        return 0;
    }
    int a=height(root->left,n);
    int b=height(root->right,n);
    n=max(n,a+b);
    return max(a,b)+1;
}
int diameterOfBinaryTree(Node* root) {
      int n=0;
      height(root,n);
      return n;
}

//top view of binary tree
void topview(Node* root){//TC->O(nlogn)
    queue<pair<Node*,int>>q;//(Node,Horizontal Distace)
    map<int,int>m;//(Horizontal Distace,Node data)
    if(root!=nullptr){
        q.push({root,0});
        while(q.size()>0){
            Node* curr=q.front().first;
            int currhd=q.front().second;
            q.pop();
            if(m.find(currhd)==m.end()){//find->O(logn)
                m[currhd]=curr->data;
            }
            if(curr->left!=nullptr){
                q.push({curr->left,currhd-1});
            }
            if(curr->right!=nullptr){
                q.push({curr->right,currhd+1});
            }
        }
        for(auto v:m){
            cout<<v.second<<" ";
        }
        cout<<endl;
    }

}

//bottom view of binary tree
void bottomView(Node* root){//TC->O(n)
    queue<pair<Node*,int>>q;//(Node,Horizontal Distace)
    map<int,int>m;//(Horizontal Distace,Node data)
    if(root!=nullptr){
        q.push({root,0});
        while(q.size()>0){
            Node* curr=q.front().first;
            int currhd=q.front().second;
            q.pop();
            m[currhd]=curr->data;
            if(curr->left!=nullptr){
                q.push({curr->left,currhd-1});
            }
            if(curr->right!=nullptr){
                q.push({curr->right,currhd+1});
            }
        }
        for(auto v:m){
            cout<<v.second<<" ";
        }
        cout<<endl;
    }
}

//print Nodes at level K
void KthLevel(Node* root,int k){
    if(root==nullptr)return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    KthLevel(root->left,k-1);
    KthLevel(root->right,k-1);  
}

//LCA(Lowest common ancestor)
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==nullptr)return root;
    if(root==p || root==q)return root;
    Node* a=lowestCommonAncestor(root->left,p,q);
    Node* b=lowestCommonAncestor(root->right,p,q);
    if(a==nullptr && b!=nullptr)return b;
    if(a!=nullptr && b==nullptr)return a;
    if(a!=nullptr && b!=nullptr)return root;
    return nullptr;
}

//Transform to sum tree
int sum(Node* root){
    if(root==nullptr)return 0;
    int left=sum(root->left);
    int rght=sum(root->right);
    root->data+=left+rght;
    return root->data;
}

//Maximum width of binary tree
//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
int widthOfBinaryTree(Node* root) {
        queue<pair<Node*,unsigned long long>>q;
        q.push({root,0});
        int maxwidth=0;
        while(q.size()>0){
            unsigned long long stIdx=q.front().second;
            unsigned long long endIdx=q.back().second;
            maxwidth=max(maxwidth,(int)(endIdx-stIdx+1));
            int cls=q.size();
            for(int  i=0;i<cls;i++){
                unsigned long long idx=q.front().second;
                Node* currNode=q.front().first;
                q.pop();
                if(currNode->left!=nullptr)q.push({currNode->left,2*idx+1});
                if(currNode->right!=nullptr)q.push({currNode->right,2*idx+2});
            }
        }
        return maxwidth;
    }

//Morris Inorder Traversal
void MorrisInorderTraversal(Node* root){
    Node* curr=root;
    while(curr!=nullptr){
        if(curr->left==nullptr){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            Node* ip=curr->left;
            while(ip->right!=nullptr && ip->right!=curr)
                ip=ip->right;
            if(ip->right==nullptr){
                ip->right=curr;//thread created 
                curr=curr->left;
        }
            else{
                ip->right=nullptr;//thread removed
                cout<<curr->data<<" ";
                curr=curr->right;
            }
            }
        }
    }

  //  114. Flatten Binary Tree to Linked List

Node* nxtr=nullptr;
void flatten(Node* root) {
    if(root==nullptr)return;
    flatten(root->right);
    flatten(root->left);
    root->left=nullptr;
    root->right=nxtr;
    nxtr=root;
}
int main()
{
    vector<int>preorder_seq={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildBintree(preorder_seq);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    Preorder_traversal(root);
    cout<<endl;
    Inorder_traversal(root);
    cout<<endl;
    Postorder_traversal(root);
    cout<<endl;
    LevelOrder_traversal2(root);
    cout<<endl;
    cout<<"Height: "<<height(root)<<endl;
    cout<<"Total Nodes: "<<countTotalNodes(root)<<endl;
    cout<<"Sum Of Nodes:"<<NodeSum(root)<<endl;
    cout<<"Diameter of Binary Tree:"<<diameterOfBinaryTree(root)<<endl;
    topview(root);
    bottomView(root);
    idx=-1;
    vector<int>preorder_seq2={1,2,7,-1,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root2=buildBintree(preorder_seq2);
    KthLevel(root2,3);
    cout<<endl;
return 0;
}