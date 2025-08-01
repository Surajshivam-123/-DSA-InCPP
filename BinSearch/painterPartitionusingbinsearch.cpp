#include<iostream>
#include<vector>
using namespace std;

/*
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. 

You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.
*/

bool isvalid(vector<int>arr,int mid,int p){//O(n)
    int n=1;
    int time=0;
for(int i=0;i<arr.size();i++){
     
        if (time+arr[i]<=mid){
         time+=arr[i];
        }
        else{
            n++;
            time=arr[i];
        }
        }
       return n<=p;
}
int maxa(vector<int>arr){
    int ans=INT16_MIN;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,arr[i]);
        }
    return ans;
    }
int sum(vector<int>arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }    
    return sum;
    }

int main(){
    vector<int>arr={40,30,10,20};
    int p=1,n;//n->number of painters
    cin>>n;
    int st=maxa(arr),end=sum(arr);
    int ans;
    while(st<=end){//O(log(sum))
        int mid=st+(end-st)/2;
        if(isvalid(arr,mid,n)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1;
        }
        
    }
    cout<<ans;
}//Total time compleity=n*log(sum)