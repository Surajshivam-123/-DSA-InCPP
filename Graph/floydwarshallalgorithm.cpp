// Floyd Warshall Algorithm
// Purpose:

// Finds the shortest paths between all pairs of vertices in a weighted graph.
// Detects negative weight cycles.
// Key Idea:

// Use Dynamic Programming to iteratively improve the shortest path between any two vertices via intermediate vertices.
// Steps:

// Start with an adjacency matrix where dist[i][j] is the weight of the edge (i, j), or ∞ if no edge exists.
// For each vertex k, check if dist[i][k] + dist[k][j] < dist[i][j] and update.
// Time Complexity:


// O(V 3) where 
// V is the number of vertices.
// Space Complexity:


// O(V 2) for the distance matrix.
// Negative Cycle:

// If dist[i][i] < 0 for any vertex i, a negative weight cycle exists.

// Example
// You are given an weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
// The graph may contain negative edge weights, but it does not contain any negative weight cycles.

bool floydWarshall(vector<vector<int>> &dist) {
        int n=dist.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dist[j][i]!=1e8 && dist[i][k]!=1e8)
                        dist[j][k]=min(dist[j][k],(dist[j][i])+dist[i][k]);
                }
            }
        }
        // to detect negative cycles
        for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j==k && dist[j][k]<0)return true;
                }
            }
            return false;
    }