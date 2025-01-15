#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>god={2,3,5,7,8};
    int st=0,end=(god.size()-1);
    int target=9;
    while(st<=end){
        if((god[st]+god[end])>target){
        end--;
        }
        else if((god[st]+god[end])<target){
        st++;
        }
       else{
        cout<<st<<','<<end;
        break;
       } 
    }
    

}