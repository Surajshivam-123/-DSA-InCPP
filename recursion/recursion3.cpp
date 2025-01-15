#include<bits/stdc++.h>
using namespace std;
//TO PRINT PERMUTATION OF NUMBER
void permute(vector<int>&arr,vector<vector<int>>&fin,int j){
    if(j==arr.size()-1){
        fin.push_back({arr});
        return;
    }
    for(int i=j;i<arr.size();i++){
        swap(arr[i],arr[j]);
        permute(arr,fin,j+1);
        swap(arr[i],arr[j]);
    }
    
}
//TC->O(n!*n)
//SC->O(n!+n)
//TO PRINT PERMUTATION OF STRING
void perms(string &giv,vector<string>&ans,int idx){
    if(idx==giv.length()-1){
        ans.push_back(giv);
        return;
    }
    for(int i=idx;i<giv.length();i++){
        swap(giv[idx],giv[i]);
        perms(giv,ans,idx+1);
        swap(giv[idx],giv[i]);
    }
}
int main(){
    vector<string>ans;
    vector<int>arr={1,2,3,4};
    string s="abc";
    perms(s,ans,0);
    for(int i=0;i<ans.size();i++){
       cout<<ans[i];
        cout<<endl;
    }
}