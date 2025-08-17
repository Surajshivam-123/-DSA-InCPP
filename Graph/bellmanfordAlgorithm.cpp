// BELLMAN FORD ALGORITHM
// Purpose: Finds the shortest path from a source to all vertices, even with negative edge weights.
// Negative Cycles: Detects if a graph contains cycles with negative total weight.
// Difference from Dijkstra: Handles negative weights; slower in comparison.
// Core Idea: Repeatedly relax all edges to update shortest paths.
// Algorithm Steps:
// Initialization:

// Set distance of the source vertex to 0.
// Set all other distances to ∞.
// Relaxation:

// Perform n-1 iterations (n = number of vertices).
// For each edge, update the distance if a shorter path is found.
// Negative Cycle Detection:

// Perform one extra iteration.
// If any edge can still be relaxed, a negative cycle exists.
// Code Structure:
// Input: Graph edges, weights, source vertex.
// Relaxation Loop: Iterate n-1 times over all edges.
// Cycle Check: Additional iteration to identify negative cycles.
// Complexity:
// Time: 
// O(V⋅E)
// O(V⋅E) (V = vertices, E = edges).
// Space: 
// O(V)
// O(V) for distance array.
// Applications:
// Networks with negative weights.
// Detecting arbitrage in currency exchange.

 vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
       vector<int>dist(V,1e8);
       dist[src]=0;
    //   Relaxation
       for(int i=0;i<V-1;i++){
           for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                   dist[v]=dist[u]+wt;
               }
           }
       }
    //   detect negative cycle
       for(auto it:edges){
               int u=it[0];
               int v=it[1];
               int wt=it[2];
               if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                   return {-1};
               }
        }
        return dist;
    }
