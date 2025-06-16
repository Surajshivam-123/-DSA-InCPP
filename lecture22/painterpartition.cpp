#include<iostream>
#include<vector>
using namespace std;
/*
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.
*/
int main(){
    //brutal approach
    int p1=0,p2=0;
    int mind=INT16_MAX;
    vector<int>arr={40,30,10,20};
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            p1+=arr[j];
        }
        for(int j=i;j<arr.size();j++){
            p2+=arr[j];
        }
        if(p2>p1){
            mind=min(p2,mind);
        }
        else{
            mind=min(p1,mind);
        }
    }
    cout<<"Minimum time would be "<<mind;
}
    