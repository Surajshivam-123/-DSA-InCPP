#include<iostream>
#include<vector>
using namespace std;
// the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
void nextPermutation(vector<int>& nums) {
        //find the pivot
        int pivot=-1,n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        //reverse the array
        if(pivot==-1){
            int m=n/2;
            for(int i=0;i<m;i++){
                swap(nums[i],nums[n-i-1]);
            }
            return;
        }
        //find the element greater then pivot
        for(int i=n-1;i>pivot;i--){
            if(nums[pivot]<nums[i]){
                swap(nums[pivot],nums[i]);
                break;
            }
        }
        //reverse the end string
        int i=pivot+1,j=n-1;
        while(i<=j){
            swap(nums[i++],nums[j--]);
        }
       }
int main(){
    vector<int>sur={1,2,3,4,5};
    //this function is alternative of above function
//next_permutation(sur.begin(),sur.end());

}