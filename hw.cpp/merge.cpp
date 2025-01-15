#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        int l=nums1[m-1];
       for(int i=0;i<(m+n);i++){
        if(nums2[j]>=l){
            nums1.insert(nums1.begin()+m+j,nums2[j]);
            nums1.pop_back();
            j++;
            continue;
        }
        else if((nums2[j]<=nums1[i])){
                nums1.insert(nums1.begin()+i,nums2[j]);
                nums1.pop_back();
                j++;
        }

       }
    }
    int main(){
        vector<int>nums1={1,2,3,0,0,0};
        vector<int>nums2={2,5,6};
        merge(nums1,3,nums2,3);
        for(int v:nums1){
            cout<<v<<endl;
        }
        
    }