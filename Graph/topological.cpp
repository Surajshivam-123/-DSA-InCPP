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

// return all nodes which is not part of any cycle

vector<int>  findsafeNodes(vector<int>adj[],int n){
    vector<int>indegree(n,0);
    queue<int>q;
    vector<int>adjRev;
    //reverse all edges
    for(int i=0;i<n;i++){
        for(int v:adj[i]){
            adjRev[v].push_back(i);
        }
    }
    calculate_indegree(adjRev,indegree,q);
    vector<int>safeNodes;
    while(!q.empty()){
        int curr=q.front();
        safeNodes.push_back(curr);
        q.pop();
        for(int v:adj[curr]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}


// Alien Dictionary
// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
string findOrder(vector<string> &words) {
    set<char>s;
    for(int i=0;i<words.size();i++){
        for(char ch:words[i]){
            s.insert(ch);
        }
    }
    map<char,vector<char>>m;
    for(int i=0;i<words.size()-1;i++){
        int l=0;
        while(l<words[i].length() && l<words[i+1].length() && words[i][l]==words[i+1][l]){
            l++;
        }
        if (l == words[i+1].length() && l < words[i].length()) {
                    return ""; // invalid ordering
        }
        if(l==words[i].length() && l==words[i+1].length()){
            continue;
        }
        m[words[i][l]].push_back(words[i+1][l]);
    }
    // topo sort
    map<char,int>indegree;
    queue<char>q;
    string str="";
    for(auto it:s){
        for(char v:m[it]){
            indegree[v]++;
        }
    }
    for(char it:s){
        if(indegree[it]==0){
            q.push(it);
        }
    }
    while(!q.empty()){
        char curr=q.front();
        str+=curr;
        q.pop();
        for(auto it:m[curr]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(s.size()!=str.length()){
        return "";
    }
    return str;
}

// optimized version of above problem
string findOrder2(vector<string> &words) {
    set<char>s;
    for(int i=0;i<words.size();i++){
        for(char ch:words[i]){
            s.insert(ch);
        }
    }
    vector<int>adj[s.size()];
    for(int i=0;i<words.size()-1;i++){
        string s1=words[i];
        string s2=words[i+1];
        int l=min(s1.length(),s2.length())
        for(int j=0;j<l;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
        }
    }
        if(s1.length()>s2.length())return "";//like if s1=abcd and s2=abc
}
    vector<int>topoSort=topoSort(s.size(),adj);
    if(topoSort.size()!=s.size())return "";//graph is cyclic
    string s="";
    for(char ch:topoSort){
        s+=(char)(ch+'a');
    }
    return s;
}
