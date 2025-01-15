#include<iostream>
#include<vector>
using namespace std;
bool isvalid(int mid,int m,vector<int>suraj){//Time complexityO(n)
        int pages=0;
        int st=1;
        for(int i=0;i<suraj.size();i++){
            if(suraj[i]>mid){
                return 0 ;
            
        }
            if(pages+suraj[i]<=mid){
                pages+=suraj[i];
            }
            else{
                st++;
                pages=suraj[i];
            }
        }
        if(st<=m){
            return 1;
        }
        else
            return 0;
        
}

int allocatebooks(vector<int>arr,int m){//Time complexity n*logn
    if(m>arr.size()){
    return -1;
    }
    int sum=0;
    for(int val:arr){
        sum+=val;
    }
    int st=0,end=sum,ans=-1;//range of possible ans
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(mid,m,arr)){//left
            ans=mid;
            end=mid-1;
        }
        else//right
            st=mid+1;
    }
    return ans;
}
int main(){
vector<int>suraj={15,17,20};
int m=2;
cout<<allocatebooks(suraj,m)<<endl;
return 0;
}