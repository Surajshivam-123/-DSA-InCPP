#include<iostream>
#include<vector>
using namespace std;

/*
Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/

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

int aggressivecows(vector<int>arr,int n){
    sort(arr.begin(),arr.end());
    int st=arr[1]-arr[0],end=arr[arr.size()-1]-arr[0];
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(ispossible(arr,mid,n)){
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