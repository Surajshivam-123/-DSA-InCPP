#include<iostream>
#include<vector>
using namespace std;
int main(){
    //brutal approach
    int p1=0,p2=0;
    int mind=INT16_MAX;
    int mint;
    vector<int>suraj={40,30,10,20};
    for(int i=1;i<suraj.size();i++){
        for(int j=0;j<i;j++){
            p1+=suraj[j];
        }
        for(int j=i;j<suraj.size();j++){
            p2+=suraj[j];
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
    