#include <iostream>
using namespace std;
//  Xenia and Bit Operations

// Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.

// Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate. In the end, she obtains a sequence consisting of one element, and that element is v.

// Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

// You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.

// Input
// The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

// Output
// Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

// Examples
// InputCopy
// 2 4
// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2
// OutputCopy
// 1
// 3
// 3
// 3
class SGTree
{
    vector<int> segt;

public:
    SGTree(int n)
    {
        segt.resize(4 * n + 1);
    }

    void build(int in, int low, int high, bool flag, vector<int> &a)
    {
        if (low == high)
        {
            segt[in] = a[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * in + 1, low, mid, !flag, a);
        build(2 * in + 2, mid + 1, high, !flag, a);

        if (flag)
            segt[in] = segt[2 * in + 1] | segt[2 * in + 2];
        else
            segt[in] = segt[2 * in + 1] ^ segt[2 * in + 2];
    }

    int query()
    {
        return segt[0];
    }

    void update(int in, int low, int high, int i, int val, bool flag)
    {
        if (low == high)
        {
            segt[in] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * in + 1, low, mid, i, val, !flag);
        else
            update(2 * in + 2, mid + 1, high, i, val, !flag);

        if (flag)
            segt[in] = segt[2 * in + 1] | segt[2 * in + 2];
        else
            segt[in] = segt[2 * in + 1] ^ segt[2 * in + 2];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    int size = pow(2, n);
    vector<int> a(size);
    for (auto &x : a)
    {
        cin >> x;
    }

    SGTree sgt(size);
    // If n is even, root does XOR; if n is odd, root does OR
    bool flag = (n % 2 == 1); // true = OR, false = XOR
    sgt.build(0, 0, size - 1, flag, a);

    while (q--)
    {
        int i, val;
        cin >> i >> val;
        sgt.update(0, 0, size - 1, i - 1, val, flag);
        cout << sgt.query() << endl;
    }
}

int main()
{
    solve();
}

//                                                  C. Sereja and Brackets
// time limit per test1 second
// memory limit per test256 megabytes
// Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

// Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

// You can find the definitions for a subsequence and a correct bracket sequence in the notes.

// Input
// The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.

// Output
// Print the answer to each question on a single line. Print the answers in the order they go in the input.

// Examples
// InputCopy
// ())(())(())(
// 7
// 1 1
// 2 3
// 1 2
// 1 12
// 8 12
// 5 11
// 2 10
// OutputCopy
// 0
// 0
// 2
// 10
// 4
// 6
// 6
// Note
// A subsequence of length |x| of string s = s1s2... s|s| (where |s| is the length of string s) is string x = sk1sk2... sk|x| (1 ≤ k1 < k2 < ... < k|x| ≤ |s|).

// A correct bracket sequence is a bracket sequence that can be transformed into a correct aryphmetic expression by inserting characters "1" and "+" between the characters of the string. For example, bracket sequences "()()", "(())" are correct (the resulting expressions "(1)+(1)", "((1+1)+1)"), and ")(" and "(" are not.

// For the third query required sequence will be «()».

// For the fourth query required sequence will be «()(())(())».
using ll = long long;

struct Node
{
    ll open = 0, close = 0, full = 0;
};

class SGTree
{
    vector<Node> segt;

public:
    SGTree(ll n)
    {
        segt.resize(4 * n + 1);
    }
    void merge(Node &res, Node &A, Node &B)
    {
        ll new_full = min(A.open, B.close);
        res.full = A.full + B.full + new_full;
        res.open = A.open + B.open - new_full;
        res.close = A.close + B.close - new_full;
    }
    void build(ll in, ll low, ll high, string &s)
    {
        if (low == high)
        {
            if (s[low] == ')')
                segt[in].close = 1;
            else
                segt[in].open = 1;
            return;
        }

        ll mid = (low + high) / 2;
        build(2 * in + 1, low, mid, s);
        build(2 * in + 2, mid + 1, high, s);

        merge(segt[in], segt[2 * in + 1], segt[2 * in + 2]);
    }

    Node query(ll in, ll low, ll high, ll l, ll r)
    {
        if (r < low || high < l)
            return Node();

        if (l <= low && high <= r)
            return segt[in];

        ll mid = (low + high) / 2;
        Node left = query(2 * in + 1, low, mid, l, r);
        Node right = query(2 * in + 2, mid + 1, high, l, r);

        Node res;
        merge(res, left, right);
        return res;
    }
};

int main()
{
    string s;
    cin >> s;
    ll n = s.size(), q;
    cin >> q;

    SGTree sgt(n);
    sgt.build(0, 0, n - 1, s);

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        Node ans = sgt.query(0, 0, n - 1, l - 1, r - 1);
        cout << 2 * ans.full << endl;
    }
}

// fenwick tree
// PS-we have an array containing only 0s and 1s 0-tail and 1-head
// in each query if query of type 1 then flip every index from head to tail and vice-versa
// in query of type-2 return number of head between l and r
class SGTreeHead
{
    vector<int> segt, lazy;

public:
    SGTreeHead(int n)
    {
        segt.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
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
        segt[in] = segt[2 * in + 1] + segt[2 * in + 2];
    }
    void update(int in, int low, int high, int l, int r)
    {
        // update the previous remaining updates and propagate downwards
        if (lazy[in] != 0)
        {
            segt[in] = (high - low + 1) - segt[in];
            if (low != high)
            { // must be  more than one children
                lazy[2 * in + 1] = !lazy[in];
                lazy[2 * in + 2] = !lazy[in];
            }
            lazy[in] = 0;
        }

        // no overlap
        if (l > high | r < low)
        {
            return;
        }
        if (l <= low && high <= r)
        { // complete overlap
            segt[in] = (high - low + 1) - segt[in];
            if (low != high)
            {
                lazy[2 * in + 1] = !lazy[2 * in + 1];
                lazy[2 * in + 2] = !lazy[2 * in + 2];
            }
            return;
        }
        // partial overlap
        int mid = (low + high) / 2;
        update(2 * in + 1, low, mid, l, r);
        update(2 * in + 2, mid + 1, high, l, r);
        segt[in] = segt[2 * in + 1] + segt[2 * in + 2];
    }
    int query(int in, int low, int high, int l, int r)
    {
        if (lazy[in != 0])
        {
            segt[in] = (high - low + 1) - segt[in];
            // propagate to its children
            if (low != high)
            {
                lazy[2 * in + 1] = !lazy[2 * in + 1];
                lazy[2 * in + 2] = !lazy[2 * in + 2];
            }
            lazy[in] = 0;
        }
        // no overlap
        if (l > high | r < low)
        {
            return 0;
        }
        // complete overlap
        if (l <= low && high <= r)
        {
            return segt[in];
        }
        // partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * in + 1, low, mid, l, r);
        int right = query(2 * in + 2, mid + 1, high, l, r);
        return left + right;
    }
};

// Once upon a time Mike and Mike decided to come up with an outstanding problem for some stage of ROI (rare olympiad in informatics). One of them came up with a problem prototype but another stole the idea and proposed that problem for another stage of the same olympiad. Since then the first Mike has been waiting for an opportunity to propose the original idea for some other contest... Mike waited until this moment!

// You are given an array a
//  of n
//  integers. You are also given q
//  queries of two types:

// Replace i
// -th element in the array with integer x
// .
// Replace each element in the array with integer x
// .
// After performing each query you have to calculate the sum of all elements in the array.

// Input
// The first line contains two integers n
//  and q
//  (1≤n,q≤2⋅105
// ) — the number of elements in the array and the number of queries, respectively.

// The second line contains n
//  integers a1,…,an
//  (1≤ai≤109
// ) — elements of the array a
// .

// Each of the following q
//  lines contains a description of the corresponding query. Description begins with integer t
//  (t∈{1,2}
// ) which denotes a type of the query:

// If t=1
// , then two integers i
//  and x
//  are following (1≤i≤n
// , 1≤x≤109
// ) — position of replaced element and it's new value.
// If t=2
// , then integer x
//  is following (1≤x≤109
// ) — new value of each element in the array.
// Output
// Print q
//  integers, each on a separate line. In the i
// -th line print the sum of all elements in the array after performing the first i
//  queries.

// Example
// Input
// 5 5
// 1 2 3 4 5
// 1 1 5
// 2 10
// 1 5 11
// 1 4 1
// 2 1
// Output
// 19
// 50
// 51
// 42
// 5
typedef long long ll;
class SGTree{
    vector<ll>segt,lazy;
    public:
    SGTree(ll n){
        segt.resize(4*n+1,0);
        lazy.resize(4*n+1,-1);
    }
    void push(ll in,ll low,ll high){
        if(lazy[in]!=-1){
            segt[in]=(high-low+1)*lazy[in];
            if(low!=high){
                lazy[2*in+1]=lazy[in];
                lazy[2*in+2]=lazy[in];
            }
            lazy[in]=-1;
        }
    }
    void build(ll in,ll low,ll high,vector<ll>&a){
        if(low==high){
            segt[in]=a[low];
            return;
        }
        ll mid=low+(high-low)/2;
        build(2*in+1,low,mid,a);
        build(2*in+2,mid+1,high,a);
        segt[in]=segt[2*in+1]+segt[2*in+2];
    }
    ll update(ll in,ll low,ll high,ll x,ll val){
        push(in,low,high);
        if(x < low || x > high) 
            return segt[in];
        if(low==high){
            return segt[in]=val;
        }
        ll mid=low+(high-low)/2;
        ll left=update(2*in+1,low,mid,x,val);
        ll right=update(2*in+2,mid+1,high,x,val);
        return segt[in]=left+right;
    }
    ll update2(ll val,ll n){
        lazy[0]=val;
        push(0,0,n-1);
        return segt[0];
    }
};

int main() {
    ll n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(auto &x:a)cin>>x;
    SGTree sgt(n);
    sgt.build(0,0,n-1,a);
    while(q--){
        ll t;
        cin>>t;
        if(t==1){
            ll x,val;
            cin>>x>>val;
            cout<<sgt.update(0,0,n-1,x-1,val)<<endl;
        }
        else{
            ll val;
            cin>>val;
            cout<<sgt.update2(val,n)<<endl;
        }
        
    }
    return 0;
}