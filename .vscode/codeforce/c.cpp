#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        long long int n,x,y;
        cin>>n>>x>>y;
        long long int a[n];
        long long int sum=0;
        for(long int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        long long int ans=0;
        x=sum-x;
        y=sum-y;
        sort(a,a+n);
        for(int i=0;i<n;i++){
             long int l=lower_bound(a,a+n,y-a[i])-a;
             long int r=upper_bound(a,a+n,x-a[i])-a;
             ans+=r-l;
             if(i>=l && i<r){
                ans--;
             }
        }
        cout<<ans/2<<endl;
    }
}