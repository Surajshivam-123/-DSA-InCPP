// Minimum Spanning Tree
// A tree in which we have n vertices and n-1 edges with total weights as minimum.
// Problem Graph:
// Vertices: 0, 1, 2, 3
// Edges with weights:

// (0, 1): 4
// (0, 2): 1
// (1, 2): 2
// (1, 3): 5
// (2, 3): 3
// Solution Graph (Prim's MST):
// Edges selected:

// (0, 2): 1
// (2, 1): 2
// (2, 3): 3
// Total weight of MST: 
// 1
// +
// 2
// +
// 3
// =
// 6
// 1+2+3=6


// Prim's Algorithm
// MST Definition: Connects all nodes with minimal edge weight, ensuring no cycles.
// Prim’s Algorithm: Greedy approach using priority queue (min-heap).
// Steps:
// Setup - Use:
// Min-heap for edge selection.
// Visited array to track nodes.
// MST list for edges included.
// Process:
// Start from any node, push (0, node, -1) to the heap.
// While heap isn’t empty:
// Extract edge with the smallest weight.
// Add it to MST if unvisited.
// Push neighbors to heap (don’t mark visited until picked).
// End: Repeat until all nodes are included.
// Complexity:
// Time: 
// O(Elog⁡V)
// O(ElogV) (heap operations).
// Space: 
// O(V+E)
// O(V+E) (visited array + heap).

int prim_algorithm(vector<pair<int,int>>adj[],int n){//SC->O(Number of Edges)
    //weight,node,parent
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    // parent node weight
    vector<pair<pair<int,int>,int>>mst;
    vector<bool>visited(n,false);
    pq.push({0,{0,-1}});
    int sum=0;
    // TC->ElogE+Eloge=>ElogE
    while(!pq.empty()){
        int weight=pq.top().first;
        int node=pq.top().second.first;
        int parent=pq.top().second.second;
        pq.pop();
        // logE
        visited[node]=true;
        sum+=weight;
        if(parent!=-1)
            mst.push_back({{parent,node},weight});
            // ElogeE
        for(auto it:adj[node]){
            if(!visited[it.first]){
                pq.push({it.second,{it.first,node}});
            }
        }
    }
    return sum;
}