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
#include<queue>
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
    for(auto adjNode:adj[node]){
        if(!visited[adjNode]){
            dfs(adj,adjNode,visited);
        }
    }
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

void bfs_of_graph(vector<int> adj[],int n,int src){//SC-O(2*N) and TC-O(N+Total degree)Total degree =2*Number of edges
    int visited[n]={0};
    queue<int>q;
    q.push(src);
    visited[src]=1;
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
#include<pair>

// DETECT A CYCLE IN UNDIRECTED GRAPH USING BFS
bool isCycle(int n,vector<int>adj[]){
    vector<bool>visited(n,false);
    // node,parent
    queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
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
// Input: grid = [[2,1,1],
            //    [1,1,0],
            //    [0,1,1]]
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
//                [0,0,0,1]]
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
// Number of distinct islands
// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

// Example 1:

// Input:
// grid[][] = [[1, 1, 0, 0, 0],
//             [1, 1, 0, 0, 0],
//             [0, 0, 0, 1, 1],
//             [0, 0, 0, 1, 1]]
// Output: 1
// Explanation:
// grid[][] = [[1, 1, 0, 0, 0], 
//             [1, 1, 0, 0, 0], 
//             [0, 0, 0, 1, 1], 
//             [0, 0, 0, 1, 1]]
// Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.

void dfs(int row,int col,vector<vector<int>>&visited,vector<vector<int>>& grid,vector<pair<int,int>>&vec,int brow,int bcol){
    int n=grid.size();
    int m=grid[0].size();
    visited[row][col]=1;
    vec.push_back({row-brow,col-bcol});
    int delRow[]={-1,0,1,0};
    int delCol[]={0,-1,0,1};
    for(int i=0;i<4;i++){
        int newRow=row+delRow[i];
        int newCol=col+delCol[i];
        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid[newRow][newCol]){
            visited[newRow][newCol]=1;
            dfs(newRow,newCol,visited,grid,vec,brow,bcol);
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {//SC-O(n*m) TC-O(NxMx4 +NxMxlog(MxN))
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    set<vector<pair<int,int>>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]==1){
                vector<pair<int,int>>vec;
                dfs(i,j,visited,grid,vec,i,j);
                s.insert(vec);
            }
        }
    }
    return s.size();
}


//Graph with 2 color such that adjacent colors are different is called as bipartite graph
// EXAMPLE
//          y-g-y-g-y
    //    /          \'
// y-g-y-g            g-y-g-y-g
//        \          /
//         y-g-y-g-y

// Linear graph with no cycle or Even cycle length is always bipartite graph
// Graph with odd length cycle is non-bipartite graph

// using bfs
bool check_bfs(vector<vector<int>>& graph, vector<int>& color, int start) {
    int n = graph.size();
    queue<int>q;
    color[start] = false;
    q.push(start);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int v : graph[curr]) {
            if (color[v] == -1) {
                q.push(v);
                color[v] = !color[curr];
            } else if (color[curr] == color[v])
                return false;
        }
        if (q.empty()) {
            for (int i = 0; i < n; i++) {
                if (color[i] == -1) {
                    q.push(i);
                    color[i] = false;
                    break;
                }
            }
        }
    }
    return true;
}

bool isBipartite_bfs(vector<vector<int>>& graph) { // SC-O(N)  TC-O(N+2E)
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!check_bfs(graph, color, i))
                return false;
        }
    }
    return true;
}

// using dfs
bool check_dfs(vector<vector<int>>& graph, vector<int>& color, int start){
    for(int v:graph[start]){
        if(color[v]==-1){
            color[v]=!color[start];
            if(!check_dfs(graph,color,v))
                return false;
        }
        else if(color[v]==color[start])
            return false;
    }
    return true;
}
bool isBipartite_dfs(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            color[i]=true;
            if(!check_dfs(graph,color,i))
                return false;
    }
}
    return true;
}

// DETECT CYCLE IN UNDIRECTED GRAPH
// usinf dfs
bool detect_cycle(vector<vector<int>>adj,vector<int>&visited,int node,vector<int>path_visited){
    visited[node]=1;
    path_visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(detect_cycle(adj,visited,it,path_visited))return true;
        }
        else if(path_visited[it]){
            return true;
        }
    }
    return false;
}
bool check_cycle_in_undirected_graph(vector<vector<int>>adj){
    int n=adj.size();
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int>path_visited(n,0);
            if(detect_cycle(adj,visited,i,path_visited))return true;
        }
    }
    return false;
}

// Safe Node
// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// Approach-All nodes which is part of cycle or connected to cycle will be not safe node
bool check(vector<vector<int>>& graph, vector<int>& visited,
               vector<int>& path_visited, vector<int>& safeNode, int node) {
        visited[node] = 1;
        path_visited[node] = 1;
        safeNode[node] = 0;
        for (int v : graph[node]) {
            if (!visited[v]) {
                if (check(graph, visited, path_visited, safeNode, v)) {
                    return true;
                }
            } else if (path_visited[v]) {
                return true;
            }
        }
        safeNode[node] = 1;
        path_visited[node] = 0;
        return false;
    }
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> path_visited(n, 0);
    vector<int> safeNode(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            check(graph, visited, path_visited, safeNode, i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (safeNode[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

// SHORTEST PATH IN UNDIRECTED GRAPH
 vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    // node distance
       queue<pair<int,int>>q;
       vector<int>dist(adj.size(),INT_MAX);
       q.push({src,0});
       dist[src]=0;
       while(!q.empty()){
           int node=q.front().first;
           int curr_dist=q.front().second;
           q.pop();
           for(auto it:adj[node]){
               if(dist[it]>curr_dist+1){
                   dist[it]=curr_dist+1;
                   q.push({it,curr_dist+1});
               }
           }
       }
       for(int i=0;i<adj.size();i++){
           if(dist[i]==INT_MAX){
               dist[i]=-1;
           }
       }
       return dist;
    }

// WORD LADDER
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {//TC-O(N*wordlength*26*logn) and 
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord)return steps;
            for(int i=0;i<word.size();i++){
                string original=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){//exist in set
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word=original;
            }
        }
        return 0;
    }

// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
// Explanation: There are 2 shortest transformation sequences:
// "hit" -> "hot" -> "dot" -> "dog" -> "cog"
// "hit" -> "hot" -> "lot" -> "log" -> "cog" 

// for interview
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        int level=0,minlevel=INT_MAX;
        vector<string>del;
        while(!q.empty()){
            vector<string>curr_v=q.front();
            string lastWord=curr_v.back();
            q.pop();
            if(curr_v.size()>level){
                level++;
                for(auto it:del){
                    s.erase(it);
                }
                del.clear();
                if(level>minlevel)break
            }
            if(lastWord==endWord){
                minlevel=level;
                if(ans.size()==0){
                    ans.push_back(curr_v);
                }else if(ans[0].size()==curr_v.size()){
                    ans.push_back(curr_v);
                }
            }
            for(int i=0;i<lastWord.size();i++){
                string original=lastWord;
                for(char ch='a';ch<='z';ch++){
                    lastWord[i]=ch;
                    if(s.find(lastWord)!=s.end()){//exist
                        curr_v.push_back(lastWord);
                        del.push_back(lastWord);
                        q.push(curr_v);
                        curr_v.pop_back();
                }
            }
            lastWord=original;
        }
    }
    return ans;
    }

// optimized approach not use in interview
class Solution {
private:
    vector<vector<string>> ans;
    map<string, int> m;
    string b;
    void dfs(string endWord, vector<string> vec) {
        if (b == endWord) {
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < endWord.size(); i++) {
            string original = endWord;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                endWord[i] = ch;
                if (m.find(endWord)!=m.end() && m[original] - 1 == m[endWord]) {
                    vec.push_back(endWord);
                    dfs(endWord,vec);
                    vec.pop_back();
                }
            }
            endWord = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        this->b=beginWord;
        queue<string> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        q.push(beginWord);
        s.erase(beginWord);
        m[beginWord] = 0;
        while (!q.empty()) {
            string word = q.front();
            int level = m[word];
            q.pop();
            m[word] = level;
            if(word==endWord)break;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (s.find(word) != s.end()) {
                        s.erase(word);
                        q.push(word);
                        m[word]=level+1;
                    }
                }
                word[i] = original;
            }
        }
        if(m.find(endWord)!=m.end()){
            vector<string> vec;
            vec.push_back(endWord);
            dfs(endWord,vec);
        }
        return ans;
    }
};
// Find Strongly Connected Components

// SCC Definition: Maximal subgraphs where every vertex is reachable from every other vertex.
// Kosaraju's Algorithm Steps:
// First DFS: Sort nodes by finishing time in a directed graph.
// Transpose Graph: Reverse all edges to isolate SCCs.
// Second DFS: Perform DFS on transposed graph in reverse finishing order.
// Intuition:
// Edge reversal prevents traversal into adjacent SCCs, isolating them.
// Sorting by finishing time ensures nodes deeper in SCCs are processed first.
// Coding Steps:
// Run DFS to store finishing times.
// Transpose the graph by reversing edges.
// Run DFS on transposed graph using stored order to identify SCCs.
// Complexity:
// Time: O(V+E)
// O(V+E) (two DFS traversals).
// Space: O(V+E)
// O(V+E) (graph storage).
// NOTE- SCC is only valid for directed graph
void dfs(int node,vector<int>&visited,vector<vector<int>> &adj,stack<int>&st){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
void dfs3(int node,vector<int>&visited,vector<vector<int>> &adj){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs3(it,visited,adj);
        }
    }
}
int kosaraju(vector<vector<int>> &adj) {
    int v=adj.size();
    // perform dfs to find sort according to finish time
    stack<int>st;
    vector<int>visited(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }
    // reverse the edges
    vector<vector<int>>adjR(v);
    for(int i=0;i<v;i++){
        visited[i]=0;
        for(auto it:adj[i]){
            adjR[it].push_back(i);
        }
    }
    // perform the dfs to find scc
    int scc=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            scc++;
            dfs3(node,visited,adjR);
        }
    }
    return scc;
}

// find bridges in the graph
// Bridge Definition: An edge whose removal increases the number of connected components in a graph.
// Tarjan's Algorithm:
// Uses DFS to calculate two values for each node:
// Time of Insertion (tin): When the node is visited in DFS.
// Lowest Time of Insertion (low): The smallest tin reachable from the node.
// Algorithm Steps:
// Perform DFS traversal and calculate tin and low for each node.
// For an edge (u, v), check if low[v] > tin[u]. If true, (u, v) is a bridge.
// Intuition:
// If low[v] > tin[u], it means v cannot reach any ancestor of u without passing through (u, v).
// Coding Highlights:
// Use adjacency list for graph representation.
// Maintain arrays for tin, low, and visited nodes.
// Pass parent node in DFS to avoid backtracking to the immediate parent.
// Complexity:
// Time: O(V+E)
// O(V+E) (DFS traversal).
// Space: O(V+E)
// O(V+E) (adjacency list and recursion stack)

class Solution {
    int timer=1;
    void dfs(int node,int parent,vector<vector<int>>&bridge,vector<vector<int>>&adj,vector<int>&visited,vector<int>&minT,vector<int>&time){//,vector<int>&time
        visited[node]=1;
        time[node]=timer;
        minT[node]=timer++;
        for(int v:adj[node]){
            if(v==parent)continue;
            if(!visited[v]){
                dfs(v,node,bridge,adj,visited,minT,time);
                minT[node]=min(minT[node],minT[v]);
                if(minT[v]>time[node]){
                    bridge.push_back({v,node});
                }
            }
            else{
                minT[node]=min(minT[node],minT[v]);
            }
        }
        
        // // if someone is smaller or equal to parent then that edge will not be considered as bridge edge
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        vector<int>minT(n);
        vector<int>time(n);
        vector<vector<int>>bridge;
        dfs(0,-1,bridge,adj,visited,minT,time);
        return bridge;
    }
};
// Definition:

// Articulation points are nodes whose removal increases the number of connected components in a graph.
// Conditions:

// A node is an articulation point if it meets:
// Root Node Condition: If the root of the DFS tree has two or more children.
// Forward Edge Condition: If any child node cannot reach an ancestor of the current node.
// DFS Algorithm:

// Use DFS to traverse the graph.
// Track time of insertion and low time for each node.
// Compare low time of child with time of parent.
// Special Cases:

// Starting nodes with multiple components.
// Nodes that are part of cycles or bridges.
// Steps to Identify Articulation Points:
// Perform DFS traversal.
// Calculate time and low values for all nodes.
// Apply articulation point conditions during backtracking.
// Code Implementation:
// Key Variables:
// visited[]: Tracks visited nodes.
// time[] and low[]: Track discovery and low times.
// parent[]: Keeps parent-child relationships.
// Logic:
// During DFS, compute and compare low values.
// Mark articulation points using hashing.
// Complexity Analysis:
// Time Complexity: O(V+E)O(V+E), where 
// V is vertices and E is edges.
// Space Complexity: O(V)
// O(V) for storing visited nodes and parent-child relationships.
int timer=1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>&visited,vector<int>&time,vector<int>&minT,vector<int>&ans){
        visited[node]=1;
        time[node]=minT[node]=timer;
        timer++;
        int child=0;
        for(int v:adj[node]){
            if(v==parent)continue;
            if(!visited[v]){
                dfs(v,node,adj,visited,time,minT,ans);
                minT[node]=min(minT[node],minT[v]);
                child++;
                if(minT[v]>=time[node] && parent!=-1){
                    ans[node]=1;
                }
            }
            else{
                minT[node]=min(minT[node],time[v]);
            }
        }
        if(child>1 && parent==-1){
            ans[node]=1;
        }
        
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
       vector<int>visited(V,0);
       vector<int>time(V);
       vector<int>minT(V);
       vector<int>ans(V,0);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,-1,adj,visited,time,minT,ans);
           }
       }
       vector<int>ap;
       for(int i=0;i<V;i++){
           if(ans[i]==1){
               ap.push_back(i);
           }
       }
        if(ap.size()==0)return {-1};
        return ap;
    }

    // All Problems
    // 1.Detect cycle in undirected graph
    // 2.Find number of different components from the adjacent matrix
    // 3.Find number of Island
    // 4.Rotten oranges
    // 5.Distance of nearest cell having 1
    // 6.Surrouding regions
    // 7.Island size
    // 8.Number of distant island
    // 9.Bipartite Graph
    // 9.Safe Node
    // 10.Shortest PATH
    // 11.Word ladder I
    // 12.Word ladder II 
    // 13.Find Strongly connected component (Kosaraju's algorithm)
    // 14.Find Bridges in the graph
    // 15.Articulation Points