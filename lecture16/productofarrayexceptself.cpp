#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf1(vector<int>& nums) {
    int pro=1;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        pro=1;
        for(int j=0;j<nums.size();j++){
            if(i!=j){
            pro*=nums[j];
        }
    }
        ans.push_back(pro);
}

return ans;
    }
vector<int> productExceptSelf(vector<int>& nums) {//[1,2,3,4]
        vector<int> ans;
        int n=nums.size();
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*nums[i-1];//[1,1,2,6,24]
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*nums[i+1];//[24,24,12,4,1]
    }
    for(int i=0;i<n;i++){
        ans[i]=prefix[i]*suffix[i];
    }
    return ans;
    }
 vector<int> productExceptSelf2(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        ans[0]=nums[0];
       for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i];
       }
       int suffi=1;
       for(int j=n-1;j>=0;j--){
       ans[j]*=suffi;
       suffi*=nums[j];

       }
       return ans;
    }

    
int main(){
vector<int>suraj={1,2,3,4};
productExceptSelf2(suraj);
for(int i=0;i<suraj.size();i++){
    cout<<suraj[i]<<endl;
}
return 0;
}