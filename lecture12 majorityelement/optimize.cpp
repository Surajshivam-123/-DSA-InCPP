#include<iostream>
#include<vector>
using namespace std;
void sorting(vector<int>& nums){
    int st=0,end=nums.size()-1;

    while(st<=end){
        if(nums[st]>nums[end]){
            swap(nums[st],nums[end]);

        }
        st++;end--;
    }
    }

int majorityElement(vector<int>& nums) {
    sorting(nums);
    int n=nums.size();
    int a=nums[0],c;
    for(int i=0;i<n;i++){
        if(a==nums[i]){
            c++;
        }
        if(c>n/2){
            return a;
        }
        else{
            c=1;
            a=nums[i];
        }
    }

}
int main(){
vector<int>suraj={1,2,2,1,1};
cout<<majorityElement(suraj);

}
