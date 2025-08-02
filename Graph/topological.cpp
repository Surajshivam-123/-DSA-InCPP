// Topological sorting
// Linear ordering of vertices such that if there is an edge between u and v ,u appears before v in that ordering
// Only possible for directed acyclic graph
//                      t5->0<-4t
//                      |       |
//                      h2->3->1h
// adjacent list 5-{0,2},4-{0,1},2-{3},3-{1}
// topo sort 5 4 2 3 1 0 or 4 5 2 3 1 0 (parent node comes before all child node)

// using dfs use stack
void dfs(vector<int> adj[],int node,vector<bool>&visited,stack<int>&st){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(adj,it,visited,st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int v, vector<int> adj[]){//SC-O(N) TC-O(V+E)
    vector<bool>visited(v,0);
    stack<int>st;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(adj,i,visited,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// using bfs(kahn's algorithm)use indegree
// indegree-number of incoming edges
void calculate_indegree(vector<vector<int>>adj,vector<int>&indegree,queue<int>&q){
    int n=adj.size();
    int m=adj[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            indegree[adj[i][j]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(indegree[adj[i][j]]==0){
                q.push(adj[i][j]);
            }
        }
    }
}
vector<int> topoSort_bfs(vector<vector<int>>adj[]){//SC-O(n) and TC-(V+2E)
    queue<int>q;
    vector<int>indegree(n,0);
    vector<int>ans;
    calculate_indegree(adj,indegree,q);
    while(!q.empty()){
        int curr=q.front();
        ans.push_back(curr);
        q.pop();//remove the node
        for(int v:adj[curr]){
            indegree[v]--;//decrese the indegree of adjacent node
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return ans;
}

// detect cycle in directed graph using toposort
// if graph would be cyclic then toposort would not have n elements but less than n
bool detectCycleInDirectedGraph(vector < vector<int>>& adj){
    int n=adj.size();
    queue<int>q;
    vector<int>indegree(n,0);
    calculate_indegree(adj,indegree,q);
    int cnt=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cnt++;
        for(int v:adj[curr]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return cnt!=n;
}

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> q;
        vector<int>indegree(numCourses,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            indegree[prerequisites[i][1]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            cnt++;
            for(int v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return cnt==numCourses;
    }