#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> prevSmallEle(vector<int>nums){//TC->O(n)
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<nums.size();i++){
        while(!s.empty() && s.top()>=nums[i]){
            s.pop();
        }
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
        s.push(nums[i]);
    }
    return ans;
}
int main(){
    vector<int>arr={3,1,0,8,6};
    vector<int>ans=prevSmallEle(arr);
    for(int v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
return 0;
}