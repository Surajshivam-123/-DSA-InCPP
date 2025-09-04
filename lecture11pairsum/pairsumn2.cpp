#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={2,3,5,7,8};
    int target=9;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if((arr[i]+arr[j])==target){
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
        }
    }
cout<<ans[0]<<','<<ans[1];
}