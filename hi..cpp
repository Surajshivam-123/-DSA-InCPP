class Solution {
public:
    vector<vector<int>> adj;
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        adj.resize(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 1;
        for(int i=0; i<n; i++) {
            // odd length palindrome
            for(int j : adj[i]) {
                for(int k : adj[i]) {
                    vector<bool> visited(n, false);
                    visited[i] = true;
                    if(j != k and label[j] == label[k])
                        ans = max(ans, 1 + fun(j, k, label, visited));
                }
            }
            // even length palindrome
            for(int j : adj[i]) {
                vector<bool> visited(n, false);
                visited.assign(n, false);
                if(label[i] == label[j])
                    ans = max(ans, fun(i, j, label, visited));
            }
        }
        return ans;
    }
    int fun(int i, int j, const string& label, vector<bool>& visited) {
        visited[i] = visited[j] = true;
        int ret = 2;
        for(int e : adj[i]) {
            for(int f : adj[j]) {
                if(e != f and label[e] == label[f] and !visited[e] and !visited[f]) {
                    ret = max(ret, 2 + fun(e, f, label, visited));
                }
            }
        }
        return ret;
    }
};
