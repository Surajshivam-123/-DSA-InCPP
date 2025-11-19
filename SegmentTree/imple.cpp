#include <iostream>
#include <vector>
using namespace std;
// Segemnt Tree-A data Structure which gives range query in logn
// PROBLEM STATEMENT-Find min element in a given range
// Brute force-number of query=q then TC-O(q*(r-l+1))

// build a segment tree which store
// take the size of segment tree 4*n which will be always sufficient to hold this
class SGTree
{
        vector<int>segt;
        public:
        SGTree(int n){
                segt.resize(4*n+1);
        }
        void build(int in, int low, int high, vector<int> &a)
        {
                if (low == high)
                {
                        segt[in] = a[low];
                        return;
                }
                int mid = (low + high) / 2;
                build(2 * in + 1, low, mid, a);
                build(2 * in + 2, mid + 1, high, a);
                segt[in] = min(segt[2 * in + 1], segt[2 * in + 2]);
        }
        // Example- l=2,r=4
        // Now start from 0 to (n-1)
        // if there is partial overlap (range [2,4] is present in curr node)
        // then compute left come back and then compute right
        // if there is complete overlap (range of curr Node is subset of [2,4])
        // return seg[in]
        // if no overlap no need to go furthur down
        // return +infinity

        int query(int in, int low, int high, int l, int r)
        { // TC-O(logn)
                if (low > r || high < l)
                { // no overlap
                        return INT_MAX;
                }
                else if (low >= l && high <= r)
                { // complete overlap
                        return segt[in];
                }
                else//partial overlap
                {
                        int mid = (low + high) / 2;
                        int left = query(2 * in + 1, low, mid, l, r);
                        int right = query(2 * in + 2, mid + 1, high, l, r);
                        return min(left, right);
                }
        }

        void update(int in, int low, int high, int i, int val)
        { // TC->O(logn)
                if (low == high)
                {
                        segt[in] = val;
                        return;
                }
                int mid = (low + high) / 2;
                if (i <= mid) // go left
                        update(2 * in + 1, low, mid, i, val);
                else // go right
                        update(2 * in + 2, mid + 1, high, i, val);
                segt[in] = min(segt[2 * in + 1], segt[2 * in + 2]);
        }
};

void solve()
{
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
        {
                cin >> x;
        }
        SGTree sg(n);
        int q;
        cin >> q;
        sg.build(0, 0, n - 1, a);
        while (q--)
        {
                int type, x, y;
                cin >> type >> x >> y;
                if (type == 1)
                {
                        sg.update(0, 0, n - 1, x, y);
                }
                else
                {
                        cout << sg.query(0, 0, n - 1, x, y) << endl;
                }
        }
}
int main()
{
        // int n=6;
        // vector<int>segt(4*n,0);
        // vector<int>arr={1,3,2,0,4,5};
        solve();
}