#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>god={2,3,5,7,8};
    int target=9;
    vector<int>suraj;
    for(int i=0;i<god.size();i++){
        for(int j=i+1;j<god.size();j++){
            if((god[i]+god[j])==target){
                suraj.push_back(god[i]);
                suraj.push_back(god[j]);
            }
        }
    }
cout<<suraj[0]<<','<<suraj[1];
}