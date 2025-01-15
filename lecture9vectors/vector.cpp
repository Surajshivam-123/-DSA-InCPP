#include<iostream>
#include<vector>
using namespace std;
int main(){
//    vector<int>suraj;
    vector<int>suraj={1,2,3,4,5,6};
    for(int val:suraj){
        cout<<val<<endl;
    }
    vector<int>pak(5,6);
    for(int val:pak){
        cout<<val<<endl;
    }
return 0;
}