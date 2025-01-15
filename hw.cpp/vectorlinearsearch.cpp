#include<iostream>
#include<vector>
using namespace std;
void linearsearchv(vector<int>nums,int ele){
    int found=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==ele){
            cout<<"Element is found and its index="<<i<<endl;
            found=1;
        }
    }
    if(found==0)
        cout<<"Not found";
}
void reversev(vector<int>&qwe){
    int start=0,end=qwe.size()-1;
    while(start<=end){
        swap(qwe[start],qwe[end]);
        start++;end--;
    }
    cout<<"IN FUnction"<<endl;
    for(int val:qwe){
        cout<<val<<endl;
    }
}
int main(){
vector<int>shivam={1,2,3,4,5,6};
linearsearchv(shivam,5);
reversev(shivam);
cout<<"IN MAIN"<<endl;
for(int val:shivam){
        cout<<val<<endl;
}
return 0;
}