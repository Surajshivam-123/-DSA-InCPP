#include<iostream>
#include<vector>
using namespace std;
//Binary Search tree:-left child is always smaller or equal to parent and right child is always greater than parent
class Node{
    public:
    int data;
    Node(int val):data(val){
        left=right=nullptr;
    }
    Node* left;
    Node* right;
};
//insert using loop
Node *insertl(Node *root,int val){
    Node* newNode=new Node(val);
    if(root==nullptr)return newNode;
    Node *temp=root;
    while (true) {
    if (val < temp->data) {
        if (temp->left == nullptr) {
            temp->left = newNode;
            break;
        }
        temp = temp->left;
    } 
    else {
        if (temp->right == nullptr) {
            temp->right = newNode;
            break;
        }
        temp = temp->right;
    }
}
    return root;
}

//insert using recursion
Node *insert(Node* root,int val){
    if(root==nullptr)
        return new Node(val);
    if(root->data>val)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
    return root;
}
//search
Node* search(Node* root,int tar){//O(Height)
    if(root==nullptr)   
        return root;
    if(root->data==tar)
        return root;
    else if(root->data>tar)
        return search(root->left,tar);
    else
        return search(root->right,tar);
}
//delete
Node *deleteNode(Node* root,int val){
    //search
    if(root==nullptr)
        return root;
    if(root->data>val)
        root->left=deleteNode(root->left,val);
    else if(root->data<val)
        root->right=deleteNode(root->right,val);
    else{
        //0 child
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        //1 child
        else if(root->left==nullptr || root->right==nullptr){
            return root->left==nullptr?root->right:root->left;
        }
        //2 child
        else{
            //inorder successor-element next to deleted element in inorder traversal
            //inorder successor is the smallest element in the right subtree or leftmost element in the right subtree
            //to find inorder successor
            Node *in_suc=nullptr;
            Node *temp=root->right;
            while(temp->left->left!=nullptr){
                temp=temp->left;
            }
            in_suc=temp->left;

            root->data=in_suc->data;
            root->right=deleteNode(root->right,root->data);
            return root;
        }
    }
}
//inorder traversal-must be in sorted order
void inorder(Node* root){
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


//build balanced binary search tree from sorted array
Node *buildBalancedTree(vector<int>nums,int st,int end){
        if(st>end)
            return nullptr;
        int mid=st+(end-st)/2;
        Node* root=new Node(nums[mid]);
        root->left=buildBalancedTree(nums,st,mid-1);
        root->right=buildBalancedTree(nums,mid+1,end);
        return root;
        
    }
Node* sortedArrayToBST(vector<int>& nums) {
    return buildBalancedTree(nums,0,nums.size()-1);
}

//validate BST
bool isBST(Node* root,Node* min,Node* max){
        if(root==NULL)
            return true;
        if((min!=NULL && root->val<=min->val) || (max!=NULL && root->val>=max->val))
            return false;
        return isBST(root->left,min,root) && isBST(root->right,root,max);
    }
bool isValidBST(Node* root) {
    Node *min=NULL,*max=NULL;
    return isBST(root,min,max);
}


//Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.
Node* prev=nullptr;

int minDiffInBST(Node* root) {
    int ans=INT_MAX;
    if(root->left!=nullptr){
        int leftMin = minDiffInBST(root->left);
        ans = min(ans,leftMin);
    }
    if(prev!=nullptr){
        ans=min(ans,root->data-prev->data);
    }
    prev=root;
    if(root->right!=nullptr){
        int rightMin=minDiffInBST(root->right);
        ans = min(ans,rightMin);
    }
    return ans;
}

int order=0;
int kthSmallest(Node* root, int k) {
    if(root==nullptr)return -1;
    int lt=kthSmallest(root->left,k);
    if(lt==-1){
        order++; 
    }
    else return lt;
    if(order==k)return root->data;
    else return kthSmallest(root->right,k);
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root->data > p->data && root->data>q->data)
            return lowestCommonAncestor(root->left,p,q);
        if(root->data < p->data && root->data < q->data)
            return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
// Construct Binary Search Tree from Preorder Traversal
//Brute force
void addNode(Node*& root,int val){
        Node* newNode=new Node(val);
        if(root==nullptr){
            root=newNode;
            return;
            }
        if(root->left==nullptr && root->right==nullptr){
            if(root->data>val)
                root->left=newNode;
            else
                root->right=newNode;
            return;
        }
        if(root->data>val)
            addNode(root->left,val);
        else
            addNode(root->right,val);
    }
Node* bstFromPreorder(vector<int>& preorder) {//O(n**2)
    Node* root=nullptr;
    for(int v:preorder){
        addNode(root,v);
    }
    return root;
}

//optimal approach
TreeNode* buildTree(int& i,int bound,vector<int>& preorder){
        if(i>=preorder.size() || preorder[i]>=bound)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=buildTree(i,root->val,preorder);
        root->right=buildTree(i,bound,preorder);
        return root;
    }
TreeNode* bstFromPreorder(vector<int>& preorder) {//O(n)
    int i=0;
    return buildTree(i,INT16_MAX,preorder);
}

//merge two binary tree
void inorderArr(Node* root,vector<int>&arr){
    if(root==nullptr)return;
    inorderArr(root->left,arr);
    arr.push_back(root->val);
    inorderArr(root->right,arr);
}

Node* merge2bst(Node* root1,Node* root2){
    vector<int>arr1;
    vector<int>arr2;
    inorderArr(root1,arr1);
    inorderArr(root2,arr2);
    vector<int>merge;
    int i=0,j=0;
    while(i!=arr1.size() && j!=arr2.size()){//O(m+n)
        if(arr1[i]<arr[j]){
            merge.push_back(arr1[i]);
            i++;
        }
        else{
            merge.push_back(arr2[j]);
            j++;
        }
    }
    while(i!=arr1.size()){
        merge.push_back(arr1[i]);
        i++;
    }
    while(j!=arr2.size()){
        merge.push_back(arr2[j]);
        j++;
    }
    //making of balanced bst using binary search
    return buildBalancedTree(merge,0,merge.size()-1);
}
//Recover Tree
//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
Node* prev=nullptr;
Node* first=nullptr;
Node* sec=nullptr;
void inorderRT(Node* root){
    if(root==nullptr)
        return;
    inorderRT(root->left);
    if(prev!=nullptr && root->data<prev->data){
        if(first==nullptr)
            first=prev;
        sec=root;
    }
    prev=root;
    inorderRT(root->right);
}
void recoverTree(Node* root){//TC->O(n)
    inorderRT(root);
    int t=first->data;
    first->data=sec->data;
    sec->data=t;
}

//largest bst
class info{
    public:
    int size;
    int max;
    int min;
    info(){}
    info(size,max,min){
        this.size=size;
        this.max=max;
        this.min=min;
    }
}
info largestBST(Node* root){//size=0
    if(root==nullptr)
        return info(0,INT16_MIN,INT16_MAX);
    info left=largestBST(root->left);
    info right=largestBST(root->right);
    if(root->data>left.max && root->data<right.min){
        info curr;
        curr.size=left.size+right.size+1;
        curr.min=min(root,left.min);
        curr.max=max(root,right.max);
        return curr;
    }
    return info(max(left.size,right.size),INT16_MAX,INT16_MIN);
}

int main(){
    Node *rootl=nullptr,*rootr=nullptr;
    vector<int>arr={5,1,7,4,8,3};

    for(int v:arr){
        rootl=insertl(rootl,v);
        rootr=insert(rootr,v);
    }
    inorder(rootl);
    cout<<endl;
    inorder(rootr);
    cout<<endl;
    Node * f=search(rootr,7);
    if(f==nullptr)
        cout<<"Not found"<<endl;
    else
        cout<<"Found "<<f->data<<endl;
    rootr=deleteNode(rootr,7);
    inorder(rootr);
    cout<<endl;
}