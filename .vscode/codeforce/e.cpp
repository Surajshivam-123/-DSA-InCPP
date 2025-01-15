#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        int b[n];
        set<int>s;
        for(int i=0;i<n;i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            s.insert(b[i]);
        }
        int msum=0;
        for(int val:s){
            int tp=k;
            int sum=0;
            int f=0;
            for(int i=0;i<n;i++){
                if(a[i]>=val){
                    sum+=val;
                }
                else if(b[i]>=val){
                        sum+=val;
                        tp--;
                }
                if(tp==-1){
                    f=1;
                    break;
                }
            }
            if(f==1)
                continue;
            if(msum<sum){
                msum=sum;
            }
        }
        cout<<msum<<endl;
    }
}