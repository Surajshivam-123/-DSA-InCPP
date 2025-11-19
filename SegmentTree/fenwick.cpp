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