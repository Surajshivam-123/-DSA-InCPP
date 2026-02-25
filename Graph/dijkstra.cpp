// Dijakstra algorithm-This algorithm helps us to find shortest path from given node to all other node of graph on the basis of weights or etc.

//Two ways

// Using priority queue


// store graph in the form of adjacency list which contain pair conataining adjacent nodes and weights .
//dijkstra does not work in negative weight or negative cycle due to infinite loops
vector<int> dijkstra(int V, vector<vector<vector<int>>> adj[], int S) {//TC-O(Elogv)or v**2log(v)
    //min-heap  distance node
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
    queue<pair<int,int>>pq;
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

// we are not using priority queue beause k is increasing continuously 
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

// Reachable nodes in subdivided graph
// You are given an undirected graph (the "original graph") with n nodes labeled from 0 to n - 1. You decide to subdivide each edge in the graph into a chain of nodes, with the number of new nodes varying between each edge.

// The graph is given as a 2D array of edges where edges[i] = [ui, vi, cnti] indicates that there is an edge between nodes ui and vi in the original graph, and cnti is the total number of new nodes that you will subdivide the edge into. Note that cnti == 0 means you will not subdivide the edge.

// To subdivide the edge [ui, vi], replace it with (cnti + 1) new edges and cnti new nodes. The new nodes are x1, x2, ..., xcnti, and the new edges are [ui, x1], [x1, x2], [x2, x3], ..., [xcnti-1, xcnti], [xcnti, vi].

// In this new graph, you want to know how many nodes are reachable from the node 0, where a node is reachable if the distance is maxMoves or less.

// Given the original graph and maxMoves, return the number of nodes that are reachable from node 0 in the new graph.

// Input: edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
// Output: 13
// Explanation: The edge subdivisions are shown in the image above.
// The nodes that are reachable are highlighted in yellow.

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2] + 1});
            adj[e[1]].push_back({e[0], e[2] + 1});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for (auto &[v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) ans++;
        }
        for (auto &e : edges) {
            int u = e[0], v = e[1], k = e[2];

            int fromU = max(0, maxMoves - dist[u]);
            int fromV = max(0, maxMoves - dist[v]);

            ans += min(k, fromU + fromV);
        }

        return ans;
    }
};


// Source to destination equal to target

// You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

// Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

// Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

// Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

// Note: You are not allowed to modify the weights of edges with initial positive weights.
// Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
// Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
// Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.

class Solution {
public:
    const int INF = 2e9;

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        vector<vector<pair<int, int>>> graph(n);

        // Step 1: Build the graph, excluding edges with -1 weights
        for (const auto& edge : edges) {
            if (edge[2] != -1) {
                graph[edge[0]].emplace_back(edge[1], edge[2]);
                graph[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        // Step 2: Compute the initial shortest distance from source to
        // destination
        int currentShortestDistance =
            runDijkstra(n, source, destination, graph);
        if (currentShortestDistance < target) {
            return vector<vector<int>>();
        }

        bool matchesTarget = (currentShortestDistance == target);

        // Step 3: Iterate through each edge to adjust its weight if necessary
        for (auto& edge : edges) {
            if (edge[2] != -1)
                continue;  // Skip edges with already known weights

            // Set edge weight to a large value if current distance matches
            // target, else set to 1
            edge[2] = matchesTarget ? INF : 1;
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);

            // Step 4: If current shortest distance does not match target
            if (!matchesTarget) {
                // Compute the new shortest distance with the updated edge
                // weight
                int newDistance = runDijkstra(n, source, destination, graph);
                // If the new distance is within the target range, update edge
                // weight to match target
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        // Return modified edges if the target distance is achieved, otherwise
        // return an empty result
        return matchesTarget ? edges : vector<vector<int>>();
    }

private:
    int runDijkstra(int n, int source, int destination,
                    const vector<vector<pair<int, int>>>& graph) {
        vector<int> minDistance(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            minHeap;

        minDistance[source] = 0;
        minHeap.emplace(0, source);

        while (!minHeap.empty()) {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (d > minDistance[u]) continue;

            for (const auto& [v, weight] : graph[u]) {
                if (d + weight < minDistance[v]) {
                    minDistance[v] = d + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }

        return minDistance[destination];
    }
};

// Shortest cycle in graph
// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.
class Solution {
    int bfs(int src,vector<vector<int>>&adj,vector<int>dist){
        int n=adj.size();
        int ans=1e9;
        queue<int>q;
        vector<int>parent(n,-1);
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int adjNode:adj[node]){
                if(dist[adjNode]==1e9){
                    dist[adjNode]=dist[node]+1;
                    parent[adjNode]=node;
                    q.push(adjNode);
                }
                else if(parent[adjNode]!=node && parent[node]!=adjNode){
                    ans=min(ans,dist[adjNode]+dist[node]+1);
                }
            }
        }
        return ans;
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>dist(n,1e9);
        int ans=1e9;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                int val=bfs(i,adj,dist);
                ans=min(ans,val);
                // cout<<val<<" ";
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};


// All Problems
// 1.Find shortest path from source to all other nodes
// 2.Find shortest path from source cell to destination cell in matrix
// 3.Hiker
// 4.Cheapest flight within k loops
// 5.Minimum multiplications to reach end
// 6.Number of ways to arrive destination
// 7.Reachable nodes in subdivided graph
// 8.Source to destination equal to target
// 9.Shortest cycle in graph