#include<iostream>
#include<vector>
using namespace std;

// brute-force
pair<int,int> pairsum(vector<int>&arr,int target){
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]+arr[j])==target){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
        return {ans[0],ans[1]};
    }
    return {-1,-1};
}
// two pointer approach
pair<int,int> pairsum(vector<int>&arr,int target){//sorted array
    int st=0,end=(arr.size()-1);
    while(st<=end){
        if((arr[st]+arr[end])>target){
            end--;
        }
        else if((arr[st]+arr[end])<target){
            st++;
        }
        else{
            return {st,end};
       } 
    }
    return {-1,-1};
}
