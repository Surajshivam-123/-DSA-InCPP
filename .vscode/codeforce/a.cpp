#include<bits/stdc++.h>
using namespace std;
int  main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        vector<int>co;
        for(int i=0;i<n;i++){
            int c=1;
            while(a[i]==a[i+1]){
                c++;
                i++;
            }
            co.push_back(c);
        }
        sort(co.begin(),co.end());
        int ans;
        int rem=0;
        int in=0;
        while(k>0 && in<co.size()){
            if(co[in]<=k && (k-co[in]>=0)){
                rem++;
                k-=co[in];
            }
            in++;
        }
        // for(int i=0;i<co.size();i++){
        //     cout<<co[i]<<" ";
        // }
        if(rem!=co.size()){
        cout<<co.size()-rem<<endl;
        }
        else{
            cout<<1<<endl;
        }

    }
    }