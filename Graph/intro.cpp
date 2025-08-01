//Graph has nodes and edges
//Binsary tree is also a type of Graph
//Types of Graph

// 1.Undireected Graph
// -Edge between both nodes 
// -no arrow
// -Undirected Cyclic Graph - Cycles is present
// -Undirected Acyclic Graph - No Cycles is present
// -Degree-Number of nodes attached to any particular node is called as Degree of that Node
// Total Degree-2*(number of edges){because every edge is attached with two nodes}


// 2.Directed Graph
// -arrow present (pointing towards one side or both side)
// -Directed Cyclic Graph - Cycles is present
// -Directed Acyclic Graph - No Cycles is present
// -Indegree-number of edges whose head towards a particular node is called as indegree of that node
// -Outdegree-number of edges whose tail towards a particular node is called as outdegree of that node



// Path-Contain lot of Nodes and each of them are reachable
// Edge Weight-we can assign a weight to every node which is called as weight of that node (default is 1)

// Graph Representation
// 6-Node 6-Edges
// 1--2---3
// |      |
// 4--5---6
//
// we can take input as [{1 2},{2 3},{3 6},{6 5},{5 4},{4 1}]

// We can store into two ways
// 1.Matrix   2.List

// Matrix
//   0  1  2  3  4  5  6
// 0 
// 1       |
// 2    |     |
// 3       |            |
// 4                |
// 5              |     |
// 6          |      |

// Space-Complexity -O(N*N)
#include<vector>
#include<iostream>
vector<vector<int>> matrix(int n,vector<pair<int,int>>in){
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<in.size();i++){
        graph[in[i].first][in[i].second]=1;
        graph[in[i].second][in[i].first]=1;
    }
    return graph;
}
// In weighted Graph
//  1   2
// 1--2---3
// |      |3
// 4--5---6
//   4  5
// Matrix
//   0  1  2  3  4  5  6
// 0 
// 1       1
// 2    1     2
// 3       2            3
// 4                4
// 5              4     5
// 6          3      5


// List
// 1--2---3
// |  |   |
// 4--5---6
// store in the form of array

// 0
// 1->{2,4}
// 2->{1,3,5}
// 3->{2,6}
// 4->{1,5}
// 5->{2,4,6}
// 6->{3,5}

// Space complexity-In undirected graph O(2*number of edges)better than matrix
// Space complexity-In Directed graph O(number of edges)
vector<int>* list(int n,vector<pair<int,int>>in){
    vector<int>adj[n+1];//array of vectors
    //Undirected Graph
    for(int i=0;i<in.size();i++){
        adj[in[i].first].push_back(in[i].second);
        adj[in[i].second].push_back(in[i].first);
    }
    //Directed Graph
    // for(int i=0;i<in.size();i++){
    //     adj[in[i].first].push_back(in[i].second);
    // }
    return adj;
}
// In weighted Graph
// we use pairs instead of int to store node as well as weight between them


// NOTE-Graph is always not connected.It can be in the form of pieces.Each pieces is called as components.
// For traversal we need visited array to keep track of already traversed node.

void dfs(vector<int> adj[],int node,vector<bool>&visited){
    visited[node]=true;
    cout<<node<<" ";
} 


void traverse(vector<int> adj[],int n){
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,i,visited);
        }
    }
}

// BREADTH FIRST SEARCH TRAVERSAL(LEVEL WISE)
// Make a Queue in which we have to push all the neighbour of back node and pop and print the back node
// Make a visited array to track whether a particular node is visited before or not

void bfs_of_graph(vector<int> adj[],int n){//SC-O(2*N) and TC-O(N+Total degree)Total degree =2*Number of edges
    int visited[n]={0};
    queue<int>q;
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it]=1;
            }
        }
    }
}


// DEPTH FIRST SEARCH TRAVERSAL
void dfs_of_graph_recursion(vector<int> adj[],int node,vector<bool>&visited){//SC-O(N)  and TC-O(N+2*E)
    visited[node]=true;
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!visited[node])
        bfs_of_graph_recursion(adj,it,visited);
    }
}

// DETECT A CYCLE IN UNDIRECTED GRAPH USING BFS
bool isCylcle(int n,vector<int>adj[]){
    vector<bool>visited(n,false);
    queue<pair<int,int>>q;
        for(int i=0;i<visited.size();i++){
                if(!visited[i]){
                    q.push({i,-1});
                    visited[i]=true;
                    while(!q.empty()){
                        int node=q.front().first;
                        int parent=q.front().second;
                        q.pop();
                        for(auto it:adj[node]){
                            if(it!=parent){
                                if(visited[it]){
                                    return true;
                                }
                                q.push({it,node});
                                visited[it]=true;
                            }
                        }
                    }
                }
            }
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(it!=parent){
                    if(visited[it]){
                        return true;
                    }
                    q.push({it,node});
                    visited[it]=true;
                }
            }
        }
    return false;
}

// DETECT A CYCLE IN UNDIRECTED GRAPH USING DFS
bool dfs(vector<bool>&visited,vector<int>adj[],int node,int parent){//SC-O(n) TC-O(N+2E)
    visited[node]=true;
    for(auto adjacentNode:adj[node]){
        if(!visited[adjacentNode]){
            if(dfs(visited,adj,adjacentNode,node)){
                return true;
            }
        }
        else if(adjacentNode!=parent){
            return true;
        }
    }
    return false;
}
bool isCycleDetected(int n,vector<int>adj[]){
    vector<bool>visited(n,false);
    for(int i=0;i<n,i++){
        if(!visited[i]){
            if(dfs(visited,adj,i,-1)){
                return true;
            }
        }
    }
    return false;
}


// Find number of different components from the adjacent matrix
bool allVisited(vector<bool>visited){
        return accumulate(visited.begin(),visited.end(),0)==visited.size();
    }
int findNumComponents(vector<vector<int>>& isConnected) {//SC-O(2*N) TC-O(N*N)
    int ans=0;
    vector<bool>visited(isConnected.size(),false);
    while(!allVisited(visited)){
        queue<int>q;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false){
                q.push(i);
                visited[i]=true;
                break;
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i] && !visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        ans++;
    }
    return ans;
}

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    if(row>=n || row<0 || col>=m || col<0 || visited[row][col] || grid[row][col]!='1')
        return;
    visited[row][col]=1;
    dfs(row+1,col,visited,grid);
    dfs(row-1,col,visited,grid);
    dfs(row,col+1,visited,grid);
    dfs(row,col-1,visited,grid);
}
int numIslands(vector<vector<char>>& grid) {//SC-O(N*N) and TC-O(N*N)
    int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int row=0;row<n;++row){
        for(int col=0;col<m;col++){
            if(!visited[row][col] && grid[row][col]=='1'){
                dfs(row,col,visited,grid);
                cnt++;
            }
        }
    }
    return cnt;
}


// ROTTEN ORANGES
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Approach
// Here we have to traverse simultaneously or level wise so we will use BFS

int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    if(!q.empty()){
        q.push({-1,-1});
    }
    int t=0;
    while(!q.empty()){
        pair<int,int>curPair=q.front();
        q.pop();
        if(curPair.first==-1 && curPair.second==-1 && !q.empty()){
            t++;
            q.push({-1,-1});
            continue;
        }
        vector<int>delrow={-1,0,1,0};
        vector<int>delcol={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=curPair.first+delrow[i];
            int newCol=curPair.second+delcol[i];
            if(newRow<n && newRow>=0 && newCol<m && newCol>=0 && grid[newRow][newCol]==1){
                grid[newRow][newCol]=2;
                q.push({newRow,newCol});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)return -1;
        }
    }
    return t;
    }

// Distance of nearest cell having 1;
// Example [[1,0,1], Output [[0,1,0],
//          [1,1,0],         [0,0,1],
//          [1,0,0]]         [0,1,2]]

vector<vector<int>> Distance_of_nearest_cell_having_1(vector<vector<int>>& grid) {//SC-O(n*m) TC-O(n*m)
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>visited(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
        }
    while(!q.empty()){
        pair<pair<int,int>,int>curPair=q.front();
        q.pop();
        int row=curPair.first.first;
        int col=curPair.first.second;
        int curDist=curPair.second;
        dist[row][col]=curDist;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];
            if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !visited[newRow][newCol]){
                    q.push({{newRow,newCol},curDist+1});
                    visited[newRow][newCol]=1;
            }
        }
    }
    return dist;
}

// SURROUNDING REGIONS
// replace all 'O' with 'X' which is completely surrounded by 'X'
// Input: board = [["X","X","X","X"]
//                 ["X","O","O","X"]
//                 ["X","X","O","X"]
//                 ["X","O","X","X"]]
// Output: [["X","X","X","X"]
//          ["X","X","X","X"] 
//          ["X","X","X","X"]
//          ["X","O","X","X"]]

void srdfs(vector<vector<char>>& board, vector < vector<int>>& visited,
             int row, int col) {
        int n = board.size();
        int m = board[0].size();
        visited[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && board[newRow][newCol]=='O') {
                srdfs(board,visited,newRow,newCol);
            }
        }
    }
void solve(vector<vector<char>>& board) {//TC-O(n*m) SC-O(n*m)
    int n = board.size();
    int m = board[0].size();
    vector < vector<int>> visited(n,vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        if (board[0][i] == 'O' && !visited[0][i]) {
            srdfs(board, visited, 0, i);
        }
            if (board[n-1][i] == 'O' && !visited[n-1][i]) {
            srdfs(board, visited, n-1, i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O' && !visited[i][0]) {
            srdfs(board, visited, i,0);
        }
        if (board[i][m-1] == 'O' && !visited[i][m-1]) {
            srdfs(board, visited, i,m-1);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && !visited[i][j]){
                board[i][j]='X';
            }
        }
    }
}

// SIMILAR PROBLEM AS ABOVE 
// Input: grid = [[0,0,0,0],
//                [0,0,1,0],
//                [0,1,1,0],
//                [0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && !visited[0][i]) {
                q.push({0, i});
                visited[0][i]=1;
            }
            if (grid[n - 1][i] == 1 && !visited[n - 1][i]) {
                q.push({n - 1, i});
                visited[n - 1][i]=1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0]=1;
            }
            if (grid[i][m - 1] == 1 && !visited[i][m - 1]) {
                q.push({i, m - 1});
                visited[i][m - 1]=1;
            }
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                    visited[newRow][newCol]=1;
                    q.push({newRow,newCol});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }