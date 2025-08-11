// Dijakstra algorithm-This algorithm helps us to find shortest path from given node to all other node of graph on the basis of weights or etc.

//Two ways

// Using priority queue
// store graph in the form of adjacency list which contain pair conataining adjacent nodes and weights .
//dijkstra does not work in negative weight or negative cycle due to infinite loops
vector<int> dijkstra(int V, vector<vector<vector<int>>> adj[], int S) {//TC-O(Elogv)or v**2log(v)
    //min-heap
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // general form of priority_queue
    // priority_queue<Type, Container, Compare>default comparator is less
    vector<int>dist(V,INT_MAX);
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int edgeweight=it[1];
            int adjNode=it[0];
            if(dis+edgeweight<dist[adjNode]){
                dist[adjNode]=dis+edgeweight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

// Using Set

vector<int> dijkstraSet(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>>s;
    vector<int>dist(V,INT_MAX);
    dist[S]=0;
    s.insert({0,S});
    while(!s.empty()){
        auto it=*(s.begin());
        int node=it.second;
        int dis=it.first;
        s.erase(it);
        for(auto it:adj[node]){
            int adjNode=it[0];
            int edgeweight=it[1];
            if(dis+edgeweight<dist[adjNode]){
                if(dist[adjNode]!=INT_MAX){
                    s.erase({dist[adjNode],adjNode});
                }
                s.insert({dis+edgeweight,adjNode});
                dist[adjNode]=dis+edgeweight;
            }
        }
    }
    return dist;
}

// we can use queue as well but it will not find minimal first and traverse lot of paths unnecessarily

// Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V=adj.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<int>dist(V,INT_MAX);
       dist[src]=0;
       pq.push({src,0});
       while(!pq.empty()){
           int node=pq.top().first;
           int distance=pq.top().second;
           pq.pop();
           for(auto it:adj[node]){
               if(distance+1<dist[it]){
                   dist[it]=distance+1;
                   pq.push({it,dist[it]});
               }
           }
       }
       for(int i=0;i<V;i++){
           if(dist[i]==INT_MAX){
               dist[i]=-1;
           }
       }
       return dist;
    }

 // Function to find the shortest path from 1 to n
//  You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

// Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 
 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {//TC-O(ElogV +N)
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>parent(n+1);
        iota(parent.begin(),parent.end(),0);
        //pair<distance,node>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push({0,1});
        dist[1]=0;
        while(!pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                if(distance+edgeWeight<dist[adjNode]){
                    dist[adjNode]=distance+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        if(dist[n]==INT_MAX)
            return {-1};
        vector<int>ans;
        ans.push_back(dist[n]);
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(node);
        reverse(ans.begin()+1,ans.end());
        return ans;
    }
    //Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 
    // If the path is not possible between source cell and destination cell, then return -1.
    // Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,(vector<int>(m,INT_MAX)));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,source});
        dist[source.first][source.second]=0;
        while(!q.empty()){
            auto it=q.front();
            int distance=it.first;
            pair<int,int>node=it.second;
            q.pop();
            if(node.first==destination.first && node.second==destination.second)
                return distance;
            vector<int>dc={-1,0,1,0};
            vector<int>dr={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newR=node.first+dr[i];
                int newC=node.second+dc[i];
                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==1 && distance+1<dist[newR][newC]){
                    dist[newR][newC]=distance;
                    q.push({distance+1,{newR,newC}});
                }
            }
        }
        return -1;
    }
