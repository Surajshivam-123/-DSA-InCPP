#include<iostream>
#include<vector>
using namespace std;
bool isvalid(vector<int>sr,int mid,int p){//O(n)
    int n=1;
    int time=0;
for(int i=0;i<sr.size();i++){
     
        if (time+sr[i]<=mid){
         time+=sr[i];
        }
        else{
            n++;
            time=sr[i];
        }
        }
       return n<=p;
}
int maxa(vector<int>sr){
    int ans=INT16_MIN;
        for(int i=0;i<sr.size();i++){
            ans=max(ans,sr[i]);
        }
    return ans;
    }
int sum(vector<int>sr){
    int sum=0;
    for(int i=0;i<sr.size();i++){
        sum+=sr[i];
    }    
    return sum;
    }

int main(){
    vector<int>suraj={40,30,10,20};
    int p=1,n;
    cin>>n;
    int st=maxa(suraj),end=sum(suraj);
    int ans;
    while(st<=end){//O(log(sum))
        int mid=st+(end-st)/2;
        if(isvalid(suraj,mid,n)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        
    }
    cout<<ans;
}//Total time compleity=n*log(sum)