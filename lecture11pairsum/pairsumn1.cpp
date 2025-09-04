#include<iostream>
#include<vector>
using namespace std;
int main(){
    //sorted array
    vector<int>arr={2,3,5,7,8};
    int st=0,end=(arr.size()-1);
    int target=9;
    while(st<=end){
        if((arr[st]+arr[end])>target){
        end--;
        }
        else if((arr[st]+arr[end])<target){
        st++;
        }
       else{
        cout<<st<<','<<end;
        break;
       } 
    }
    

}