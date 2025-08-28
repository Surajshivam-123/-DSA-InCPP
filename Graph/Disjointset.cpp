// Disjoint Set 
// we can find if two node are in the same component or not in constant time complexity
// It uses the concepts of "find parent" and "union" operations, which can be implemented using either "union by rank" or "union by size" techniques.

// (Union by rank)TC-O(4-alpha)
// Union(u,v)
// STEP1:-find ultimate parent of u and v say pu and pv respectively
// STEP2:-find rank of ultimate parent
// STEP3:-connect smaller rank to larger rank always (any in case of equal rank)
// rank-height of node

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);//path compression
    }
    void unionByRank(int u,int v){
        int pu=findUltimateParent(u);
        int pv=findUltimateParent(v);
        if(pu==pv)return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;//we connect smaller to larger to avoid long traversal(when longer will be connected to smaller)
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    void unionBySize(int u,int v){
        int pu=findUltimateParent(u);
        int pv=findUltimateParent(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pu]+=size[pv];
        }
        else{
            parent[pv]=pu;
            size[pv]+=size[pu];
        }
    }
};

// kruskals algorithm to solve minimum spanning tree
int minimumSpanningTree(int v,vector<pair<int,int>>adj[]){
    vector<pair<int,pair<int,int>>>edges;
    // O(N+E)
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int node=i;
            int adjNode=it.first;
            int weight=it.second;
            edges.push_back({weight,{node,adjNode}});
        }
}   
    // MlogM M-total edges
    sort(edges.begin(),edges.end());
    DisjointSet ds(v);
    int mst=0;
    // Mx4xalpha
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
            mst+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mst;
}

// NUMBER OF PROVINCES oR NUMBER OF DIFFERENT COMPONENTS
int NumberOfProvinces(vector<vector<int>>adj,int v){//adjacency matrix
    DisjointSet ds(v);
    for(int i=0;i<v;i++){//O(V*V)
       for(int j=0;j<v;j++){
            if(adj[i][j]==1){
                ds.unionBySize(i,j);
            }
       }
    }
    int cnt=0;
    for(int i=0;i<v;i++){//O(V)
        if(ds.findUltimateParent(i)==i)
            cnt++;
    }
    return cnt;
}

// CONNECTING THE GRAPH
// You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to connect the graph.
// If it is not possible to connect the graph, return -1.

// Example 1: 

// Input:
// n = 4
// m = 3
// Edges = [ [0, 1] , [0, 2] , [1, 2] ]
// Output:
// 1
// Explanation:
// Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        vector<pair<int,int>>extra;
        for(auto it:edge){
            int ul_u=ds.findUltimateParent(it[0]);
            int ul_v=ds.findUltimateParent(it[1]);
            if(ul_u!=ul_v){
                ds.unionBySize(it[0],it[1]);
            }
            else{
                extra.push_back({it[0],it[1]});
            }
        }
        int nc=0;
        for(int i=0;i<n;i++){
            if(ds.findUltimateParent(i)==i)
                nc++;
        }
        if(nc-1<=extra.size()){
            return nc-1;
        }
        return -1;
    }

// ACCOUNT MERGE


// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // mapping of email to its index of owner
        int n=accounts.size();
        unordered_map<string,int>mp;
        DisjointSet ds(n);
        for(int j=0;j<n;j++){
            for(int i=1;i<accounts[j].size();i++){
                if(mp.find(accounts[j][i])!=mp.end()){
                    ds.unionBySize(mp[accounts[j][i]],j);//if already present then merge both index
                }
                else{
                    mp[accounts[j][i]]=j;
                    }
            }
        }
       vector<vector<string>>mergedMail(n);
       for(auto it:mp){
            int ul_p=ds.findUltimateParent(it.second);
            mergedMail[ul_p].push_back(it.first);
       }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto v:mergedMail[i]){
                temp.push_back(v);
            }
            ans.push_back(temp);
        }
        return ans;
    }

//     Number Of Islands
// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

 

// Example 1:

// Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}

// Output: 1 1 2 2
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
       vector<vector<int>>mat(n,vector<int>(m,0));
       vector<int>ans;
       DisjointSet ds(n*m-1);
       int cnt=0;
       for(auto it:operators){
           int row=it[0];
           int col=it[1];
           if(mat[row][col]){
               ans.push_back(cnt);
               continue;
           }
           mat[row][col]=1;
           vector<int>delRow={-1,0,1,0};
           vector<int>delCol={0,-1,0,1};
           cnt++;
           for(int i=0;i<4;i++){
               int newR=row+delRow[i];
               int newC=col+delCol[i];
               if(newR>=0 && newC>=0 && newR<n && newC<m && mat[newR][newC]==1){
                   int curr_ul_p=ds.findUltimateParent(row*m+col);
                   int ul_p=ds.findUltimateParent(newR*m+newC);
                   if(curr_ul_p!=ul_p){ 
                       ds.unionBySize(row*m+col,newR*m+newC);
                       cnt--;
                   }
               }
               
           }
           ans.push_back(cnt);
       }
        return ans;
    }
 

 
int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // if 3 and 7 same or not
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
    ds.unionBySize(3,7);
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
}