#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int>moore={2,2,1,1,1,2,2};
int f=0,ans=0;
for(int i=0;i<moore.size();i++){
if(f==0){
    ans=moore[i];
}
if(ans==moore[i]){
f++;
}
else{
    f--;
}
}
cout<<ans;
}