#include<iostream>
#include<vector>
using namespace std;
// when we want to update range of values rather than single element in segment tree
// here we will build an extra lazy space for every index

//To update the value from L to R
// Traverse in seg tree
// check if the node completely overlaps with (L-R)
//      update the node
//      lazy propagate down and returns
//check if the nodes partially overlaps
//      left
//      right
//      node=left+right
// no overlap 
//      return
// whenever we visit any node and update which we have previously left

// Range Sum
class SGTreeSum{
    vector<int>segt,lazy;
    public:
    SGTreeSum(int n){
        segt.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void build(int in,int low,int high,vector<int>&a){
        if(low==high){
            segt[in]=a[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*in+1,low,mid,a);
        build(2*in+2,mid+1,high,a);
        segt[in]=segt[2*in+1]+segt[2*in+2];
    }
    void update(int in,int low,int high,int l,int r,int val){
        // update the previous remaining updates and propagate downwards
        if(lazy[in]!=0){
            segt[in]+=(high-low+1)*lazy[in];
            if(low!=high){//must be  more than one children
                lazy[2*in+1]+=lazy[in];
                lazy[2*in+2]+=lazy[in];
            }
            lazy[in]=0;
        }

        // no overlap
        if(l>high | r<low){
            return;
        }
        if(l<=low && high<=r){//complete overlap
            segt[in]=segt[in]+(high-low+1)*val;
            if(low!=high){
                lazy[2*in+1]+=val;
                lazy[2*in+2]+=val;
            }
            return;
        }
        //partial overlap
        int mid=(low+high)/2;
        update(2*in+1,low,mid,l,r,val);
        update(2*in+2,mid+1,high,l,r,val);
        segt[in]=segt[2*in+1]+segt[2*in+2];
    }
    int query(int in,int low,int high,int l,int r){
        if(lazy[in!=0]){
            segt[in]+=(high-low+1)*lazy[in];
            // propagate to its children
            if(low!=high){
                lazy[2*in+1]+=lazy[in];
                lazy[2*in+2]+=lazy[in];
            }
            lazy[in]=0;
        }
        // no overlap
        if(l>high | r<low){
            return 0;
        }
        //complete overlap
        if(l<=low && high<=r){
            return segt[in];
        }
        //partial overlap
        int mid=(low+high)/2;
        int left=query(2*in+1,low,mid,l,r);
        int right=query(2*in+2,mid+1,high,l,r);
        return left+right;
    }
};
// Range Min
class SGTreeMin{
    vector<int>segt,lazy;
    public:
    SGTreeMin(int n){
        segt.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void build(int in,int low,int high,vector<int>&a){
        if(low==high){
            segt[in]=a[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*in+1,low,mid,a);
        build(2*in+2,mid+1,high,a);
        segt[in]=min(segt[2*in+1],segt[2*in+2]);
    }
    void update(int in,int low,int high,int l,int r,int val){
        // update the previous remaining updates and propagate downwards
        if(lazy[in]!=0){
            segt[in]+=lazy[in];//minimum will also increase by lazy[in]
            if(low!=high){//must be  more than one children
                lazy[2*in+1]+=lazy[in];
                lazy[2*in+2]+=lazy[in];
            }
            lazy[in]=0;
        }

        // no overlap
        if(l>high | r<low){
            return;
        }
        if(l<=low && high<=r){//complete overlap
            segt[in]+=val;
            if(low!=high){
                lazy[2*in+1]+=val;
                lazy[2*in+2]+=val;
            }
            return;
        }
        //partial overlap
        int mid=(low+high)/2;
        update(2*in+1,low,mid,l,r,val);
        update(2*in+2,mid+1,high,l,r,val);
        segt[in]=min(segt[2*in+1],segt[2*in+2]);
    }
    int query(int in,int low,int high,int l,int r){
        if(lazy[in!=0]){
            segt[in]+=lazy[in];
            // propagate to its children
            if(low!=high){
                lazy[2*in+1]+=lazy[in];
                lazy[2*in+2]+=lazy[in];
            }
            lazy[in]=0;
        }
        // no overlap
        if(l>high | r<low){
            return 0;
        }
        //complete overlap
        if(l<=low && high<=r){
            return segt[in];
        }
        //partial overlap
        int mid=(low+high)/2;
        int left=query(2*in+1,low,mid,l,r);
        int right=query(2*in+2,mid+1,high,l,r);
        return min(left,right);
    }
};
int main(){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        SGTreeSum sgt(n);
        sgt.build(0,0,n-1,arr);
        int q;
        cin>>q;
        while(q--){
            int type;
            cin>>type;
            if(type==1){
                int l,r,val;
                cin>>l>>r>>val;//1 indexing
                sgt.update(0,0,n-1,l-1,r-1,val);
            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<sgt.query(0,0,n-1,l,r)<<endl;
            }
        }
}

//find the minimum number of swap to arrange into ascending order of binary string after each query
struct SegTree {
    int n;
    vector<int> cnt1;   
    vector<int> maxZero;
    vector<int> lazy;    // -1: none, 0: set to 0, 1: set to 1

    SegTree(int size) {
        n = size;
        cnt1.assign(4 * n, 0);
        maxZero.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
        build(1, 1, n);
    }

    void build(int node, int l, int r) {
        if (l == r) {
            cnt1[node] = 0;
            maxZero[node] = l; 
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        pull(node, l, r);
    }

    void pull(int node, int l, int r) {
        cnt1[node] = cnt1[node * 2] + cnt1[node * 2 + 1];
        maxZero[node] = max(maxZero[node * 2], maxZero[node * 2 + 1]);
    }

    void apply(int node, int l, int r, int val) {
        if (val == 0) {
            cnt1[node] = 0;
            maxZero[node] = r; // all zeros
        } else { // val == 1
            cnt1[node] = r - l + 1;
            maxZero[node] = 0; // no zeros
        }
        lazy[node] = val;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != -1) {
            int mid = (l + r) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);
            lazy[node] = -1;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid) update(node * 2, l, mid, ql, qr, val);
        if (qr > mid) update(node * 2 + 1, mid + 1, r, ql, qr, val);
        pull(node, l, r);
    }

    int query_sum(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return cnt1[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        int res = 0;
        if (ql <= mid) res += query_sum(node * 2, l, mid, ql, qr);
        if (qr > mid) res += query_sum(node * 2 + 1, mid + 1, r, ql, qr);
        return res;
    }

    int total_ones() { return cnt1[1]; }
    int last_zero() { return maxZero[1]; }
    int prefix_ones(int idx) {
        if (idx < 1) return 0;
        return query_sum(1, 1, n, 1, idx);
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    SegTree st(N);

    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int L, R;
            cin >> L >> R;
            st.update(1, 1, N, L, R, 0);
        } else if (type == 1) {
            int L, R;
            cin >> L >> R;
            st.update(1, 1, N, L, R, 1);
        } else { // type == 2
            int zeros = N - st.total_ones();
            if (zeros > 0)
                st.update(1, 1, N, 1, zeros, 0);
            if (zeros < N)
                st.update(1, 1, N, zeros + 1, N, 1);
        }

        int last = st.last_zero();
        if (last == 0) {
            cout << "1\n";
        } else {
            int ones_before = st.prefix_ones(last - 1);
            cout << 1 + ones_before << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}