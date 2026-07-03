#include <bits/stdc++.h>
using namespace std;

bool issubs(const vector<int>& a, const vector<int>& b) {
    int j = 0;
    for (int x : a) {
        if (j < (int)b.size() && x == b[j]) j++;
    }
    return j == (int)b.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        string A, B;
        cin >> N >> A >> B;

        vector<int> SA, SB;

        for (int i = 0; i + 1 < N; i++) {
            if (A[i] != A[i + 1]) {
                SA.push_back((A[i] == '0' && A[i + 1] == '1') ? 1 : -1);
            }
            if (B[i] != B[i + 1]) {
                SB.push_back((B[i] == '0' && B[i + 1] == '1') ? 1 : -1);
            }
        }
        if (SB.empty()) {
            if (SA.empty()) {
                cout << (A == B ? "Yes\n" : "No\n");
            } else {
                cout << "Yes\n"; 
            }
            continue;
        }
        if (!issubs(SA, SB)) {
            cout << "No\n";
            continue;
        }

        bool fd = (B[0] != A[0]);
        bool ld  = (B[N - 1] != A[N - 1]);

        bool ans = true;

        if (fd && ld) {
            vector<int> temp = SA;
            if (!temp.empty()) temp.erase(temp.begin());
            if (!temp.empty()) temp.pop_back();
            ans = issubs(temp, SB);
        } else if (fd) {
            vector<int> temp = SA;
            if (!temp.empty()) temp.erase(temp.begin());
            ans = issubs(temp, SB);
        } else if (ld) {
            vector<int> temp = SA;
            if (!temp.empty()) temp.pop_back();
            ans = issubs(temp, SB);
        }

        cout << (ans ? "Yes\n" : "No\n");
    }

    return 0;
}