#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent, depth, heavy, head, pos, subtree;
    int curPos;

    vector<int> segtree;
    int n;

    void buildSeg(vector<int>& base, int idx, int l, int r) {
        if (l == r) {
            segtree[idx] = base[l];
            return;
        }
        int mid = (l + r) / 2;
        buildSeg(base, idx * 2, l, mid);
        buildSeg(base, idx * 2 + 1, mid + 1, r);
        segtree[idx] = segtree[idx * 2] ^ segtree[idx * 2 + 1];
    }

    void updateSeg(int idx, int l, int r, int posi, int val) {
        if (l == r) {
            segtree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (posi <= mid)
            updateSeg(idx * 2, l, mid, posi, val);
        else
            updateSeg(idx * 2 + 1, mid + 1, r, posi, val);

        segtree[idx] = segtree[idx * 2] ^ segtree[idx * 2 + 1];
    }

    int querySeg(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return segtree[idx];

        int mid = (l + r) / 2;
        return querySeg(idx * 2, l, mid, ql, qr) ^
               querySeg(idx * 2 + 1, mid + 1, r, ql, qr);
    }
    int dfs(int u, vector<vector<int>>& adj) {
        subtree[u] = 1;
        int maxSub = 0;

        for (int v : adj[u]) {
            if (v == parent[u]) continue;

            parent[v] = u;
            depth[v] = depth[u] + 1;

            int sub = dfs(v, adj);
            subtree[u] += sub;

            if (sub > maxSub) {
                maxSub = sub;
                heavy[u] = v;
            }
        }
        return subtree[u];
    }
    void decompose(int u, int h, vector<int>& base, string& s) {
        head[u] = h;
        pos[u] = curPos++;

        base[pos[u]] = (1 << (s[u] - 'a'));

        if (heavy[u] != -1)
            decompose(heavy[u], h, base, s);

        for (int v : adjGlobal[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, base, s);
        }
    }

    vector<vector<int>> adjGlobal;
    int queryPath(int u, int v) {
        int res = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            res ^= querySeg(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        res ^= querySeg(1, 0, n - 1, pos[u], pos[v]);

        return res;
    }

    vector<bool> treeQueries(int n_, vector<vector<int>>& edges,
                            string s, vector<string>& queries) {

        auto suneravilo = edges;

        n = n_;
        adjGlobal.assign(n, {});

        for (auto &e : edges) {
            adjGlobal[e[0]].push_back(e[1]);
            adjGlobal[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree.assign(n, 0);

        dfs(0, adjGlobal);

        vector<int> base(n);
        curPos = 0;
        decompose(0, 0, base, s);

        segtree.assign(4 * n, 0);
        buildSeg(base, 1, 0, n - 1);

        vector<bool> answer;

        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                s[u] = c;
                int mask = (1 << (c - 'a'));
                updateSeg(1, 0, n - 1, pos[u], mask);
            }
            else {
                int u, v;
                ss >> u >> v;

                int mask = queryPath(u, v);

                // Palindrome check: at most 1 odd count
                answer.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return answer;
    }
};
