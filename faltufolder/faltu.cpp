#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int Longest_SubArray(vector<int>nums,int k){
    vector<int>prefix(n,0);
    queue<int>temp;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        q.push(nums[i]);
        if(sum==k && maxlen<q.size()){
            maxlen=q.size();
            q.pop();
        }
        else if(sum>=k){
            q.pop();
        }
    }
    return maxlen;

}

int main()
{
    vector<int>nums={1,2,3,1,1,1,1};
    cout<<Longest_SubArray(nums,3)<<endl;
return 0;
}