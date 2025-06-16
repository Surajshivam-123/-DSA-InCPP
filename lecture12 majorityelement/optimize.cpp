#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int c=1,ans=nums[0];
    for(int i=1;i<n;i++){
        if(ans==nums[i]){
            c++;
        }
        else{
            c=1;
            ans=nums[i];
        }
        if(c>n/2){
            return a;
        }
    }

}
int main(){
vector<int>suraj={1,2,2,1,1};//1 1 2 2 1
cout<<majorityElement(suraj);

}
