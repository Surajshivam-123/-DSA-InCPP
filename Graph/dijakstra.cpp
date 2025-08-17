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


//     You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example 1:



// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

int minimumEffortPath(vector<vector<int>>& heights) {
    int n=heights.size();
    int m=heights[0].size();
    vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
    //{effort,{current box}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{0,0}});
    effort[0][0]=0;
    while(!q.empty()){
    int eff=q.top().first;
    pair<int,int>box=q.top().second;
    vector<int>dc={-1,0,1,0};
    vector<int>dr={0,1,0,-1};
    if(box.first==n-1 && box.second==m-1)return eff;
    q.pop();
    for(int i=0;i<4;i++){
        int newR=box.first+dr[i];
        int newC=box.second+dc[i];
        int ef=INT_MAX;
        if(newR>=0 && newR<n && newC>=0 && newC<m){
            ef=max(abs(heights[newR][newC]-heights[box.first][box.second]),eff);
        }
        if(newR>=0 && newR<n && newC>=0 && newC<m && ef<effort[newR][newC]){
            effort[newR][newC]=ef;
            q.push({ef,{newR,newC}});
        }
    }
    }
    return effort[n-1][m-1];
}


// CHEAPEST FLIGHTS WITHIN K LOOPS
// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

// Example 1:


// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

// we are not using priority queue beause k is increasin continuously 
//SO TC->O(E(number of edges))
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    int route=flights.size();
    for(int i=0;i<route;i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }
    // {k,{price,current}}
    queue<pair<int,pair<int,int>>>pq;
    vector<int>price(n,INT_MAX);
    pq.push({-1,{0,src}});
    price[src]=0;
    while(!pq.empty()){
        int ck=pq.front().first;
        int cp=pq.front().second.first;
        int node=pq.front().second.second;
        pq.pop();
        if(ck+1<=k){
            for(auto it:adj[node]){
                if(cp+it.second<price[it.first]){
                    price[it.first]=cp+it.second;
                    pq.push({ck+1,{price[it.first],it.first}});
                }
            }
        }
    }
    if(price[dst]==INT_MAX)
        return -1;
    return price[dst];
}

// Minimum Multiplications to reach End
// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

// Example 1:

// Input:
// arr[] = {2, 5, 7}
// start = 3, end = 30
// Output:
// 2
// Explanation:
// Step 1: 3*2 = 6 % 100000 = 6 
// Step 2: 6*5 = 30 % 100000 = 30
int minimumMultiplications(vector<int>& arr, int start, int end) {
       //value , step
       int mod=100000;
       queue<pair<int,int>>q;
       vector<int>stp(mod,INT_MAX);
       q.push({start,0});
       stp[start]=0;
       if(start==end)return 0;
       while(!q.empty()){
           int value=q.front().first%mod;
           int step=q.front().second;
           q.pop();
           for(int v:arr){
               int num=(value*v)%mod;
               if(num==end)return step+1;
               else if(step+1<stp[num]){
                   stp[num]=step+1;
                   q.push({num,step+1});
               }
           }
       }
       return -1;
    }

// NUMBER OF WAYS TO ARRIVE AT DESTINATION
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

// Example 1:


// Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
// Output: 4
// Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
// The four ways to get there in 7 minutes are:
// - 0 ➝ 6
// - 0 ➝ 4 ➝ 6
// - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
// - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

int countPaths(int n, vector<vector<int>>& roads) {//TC-O(ElogV)
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // time,node
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>pq;
        vector<long long int>time(n,LLONG_MAX);
        vector<long long int>ways(n,0);
        pq.push({0,0});
        time[0]=0;
        ways[0]++;
        int mod=1000000007;
        while(!pq.empty()){
            long long int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                long long int et=it.second;
                if(t+et<time[adjNode]){
                    time[adjNode]=t+et;
                    pq.push({time[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(t+et==time[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])% mod;
                }
            }
        }
        return ways[n-1] % mod;
}

// 