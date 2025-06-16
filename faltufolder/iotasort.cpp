#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>v={50,60,70,78,45,34};
vector<int>th(6);
iota(th.begin(),th.end(),0);
for(int va:th){
    cout<<va<<" ";
}
cout<<endl;
sort(th.begin(),th.end(),[&](int a, int b){
    return v[a]>v[b];
});
for(int va:th){
    cout<<va<<" ";
}
cout<<endl;
for(int va:v){
    cout<<va<<" ";
}
cout<<endl;
return 0;
}