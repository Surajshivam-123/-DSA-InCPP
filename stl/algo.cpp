#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//to sort according to 2nd value of pair
bool comparator(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.second<p2.second)return true;
    return false;
}
int main(){
    vector<pair<int,int>>s={{1,4},{2,5},{3,1}};
    sort(s.begin(),s.end(),comparator);
    for(auto i:s){
        cout<<i.first<<" "<<i.second<<endl;
    }
}