#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//STEPS
//BY SURAJ
void quicksort(int st,int e,vector<int>&arr){
    if(st>=e)
        return;

    int p=arr[e];
    for(int i=st;i<e;i++){
            if(arr[i]>=p){
                arr.push_back(arr[i]);
                arr.erase(arr.begin()+i);
                e--;
                i--;
        }
    }
    //left half
    quicksort(st,e-1,arr);
    //right half
    quicksort(e+1,arr.size()-1,arr);
}
int main(){
    vector<int>arr={8,7,6,5,4,3,2,1};
    quicksort(0,arr.size()-1,arr);
    // int e=arr.size()-1;
    // int p=arr[e];
    // for(int i=1;i<e;i++){
    //         if(arr[i]>p){
    //             arr.push_back(arr[i]);
    //             arr.erase(arr.begin()+i);
    //             e--;
    //             i--;
    //         }
    //     }
    for(int v:arr){
        cout<<v<<" ";
    }
    // cout<<endl<<e;
}