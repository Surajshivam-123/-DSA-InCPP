#include<iostream>
#include<vector>
using namespace std;
vector<int> sort(vector<int>&sur){
    int t;
    for(int i=0;i<sur.size();i++){
        int minn=INT16_MAX;
        for(int j=i;j<sur.size();j++){
            if(sur[j]<minn){
                minn=sur[j];
                t=sur[i];
                sur[i]=minn;
                sur[j]=t;
            }
                    }
        
    }
    return sur;
}
bool ispossible(vector<int>arr,int mid,int n){
                int c=1;
                int laststall=arr[0];
                for(int i=0;i<arr.size();i++){
                    if((arr[i]-laststall)>=mid){
                        c++;
                        laststall=arr[i];
                    }
                    if(c==n){
                     return true;
                    }  
                }
                     return false;
   
}

int aggressivecows(vector<int>sur,int n){
    sort(sur);
    int st=sur[1]-sur[0],end=sur[sur.size()-1]-sur[0];
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(ispossible(sur,mid,n)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }

    }
    return ans; 
}
int main(){
    vector<int>arr={1,4,2,9,8};
    int n;
    cin>>n;
    cout<<aggressivecows(arr,n);
    
}