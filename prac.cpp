#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for a node in the Palindromic Tree
struct Node {
    int next[26];
    int len;
    int link;
    int cnt;        // Frequency of this palindromic substring
    int degree;     // Palindromic degree of this substring
};

const int MAXN = 100005;
Node tree[MAXN];
int sz, suffixLink;
string s;
 
// Initialize the Palindromic Tree
void initTree() {
    // Node 1 is the root for odd-length palindromes (len = -1)
    tree[1].len = -1; tree[1].link = 1;
    // Node 2 is the root for even-length palindromes (len = 0)
    tree[2].len = 0;  tree[2].link = 1;
    
    for(int i = 0; i < 26; ++i) {
        tree[1].next[i] = tree[2].next[i] = 0;
    }
    
    sz = 2;
    suffixLink = 2;
}

// Insert character at position 'pos' into the tree
void extend(int pos) {
    int cur = suffixLink, curLen = 0;
    int ch = s[pos] - 'a';

    while (true) {
        curLen = tree[cur].len;
        if (pos - 1 - curLen >= 0 && s[pos - 1 - curLen] == s[pos])
            break;
        cur = tree[cur].link;
    }

    if (tree[cur].next[ch]) {
        suffixLink = tree[cur].next[ch];
        tree[suffixLink].cnt++;
        return;
    }

    sz++;
    suffixLink = sz;
    tree[sz].len = tree[cur].len + 2;
    tree[sz].cnt = 1;
    tree[sz].degree = 0;
    for(int i = 0; i < 26; ++i) tree[sz].next[i] = 0;

    tree[cur].next[ch] = sz;

    if (tree[sz].len == 1) {
        tree[sz].link = 2;
        return;
    }

    while (true) {
        cur = tree[cur].link;
        curLen = tree[cur].len;
        if (pos - 1 - curLen >= 0 && s[pos - 1 - curLen] == s[pos]) {
            tree[sz].link = tree[cur].next[ch];
            break;
        }
    }
}

void solve() {
    cin >> s;
    initTree();

    int n = s.length();
    // Maps each node to the node representing its left half
    // left_half_node[i] stores the tree node index for the floor(len/2) prefix of node i
    vector<int> left_half_node(n + 3, 0);
    
    // Step 1: Build the Palindromic Tree and track the ending node of prefixes
    // To efficiently find the left half of a palindrome, we can map prefixes.
    vector<int> prefix_node(n, 0); 
    int curr = 2; // start at even root
    
    for (int i = 0; i < n; ++i) {
        extend(i);
        prefix_node[i] = suffixLink;
    }

    // Propagate counts from longest to shortest palindromes
    for (int i = sz; i > 2; --i) {
        tree[tree[i].link].cnt += tree[i].cnt;
    }

    // Step 2: Associate each node with its left half node
    // We can find the node corresponding to the left half using the prefix map
    // For a node ending at 'i' with length 'L', its left half ends at 'i - L + L/2'
    // Let's iterate through the string and find the node for the left half of each distinct palindrome
    curr = 2;
    initTree(); // Reset to re-trace and capture exact substring nodes accurately
    for (int i = 0; i < n; ++i) {
        extend(i);
        int node = suffixLink;
        int L = tree[node].len;
        if (L > 0 && left_half_node[node] == 0) {
            if (L == 1) {
                left_half_node[node] = -1; // Special indicator for length 1
            } else {
                int half_len = L / 2;
                int half_end_idx = i - L + half_len;
                left_half_node[node] = prefix_node[half_end_idx];
            }
        }
    }

    // Step 3: Compute DP degrees and accumulate the result
    long long total_palindromic_degree = 0;
    
    // Base cases for roots
    tree[1].degree = 0;
    tree[2].degree = 0;

    // Process nodes by length (topological order is naturally guaranteed from 3 to sz since child nodes have greater lengths)
    for (int i = 3; i <= sz; ++i) {
        int L = tree[i].len;
        if (L == 1) {
            tree[i].degree = 1;
        } else {
            int half_node = left_half_node[i];
            // The left half must be a valid palindrome of length exactly floor(L/2)
            if (half_node > 2 && tree[half_node].len == L / 2) {
                tree[i].degree = 1 + tree[half_node].degree;
            } else {
                tree[i].degree = 1;
            }
        }
        total_palindromic_degree += (long long)tree[i].degree * tree[i].cnt;
    }

    cout << total_palindromic_degree << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}