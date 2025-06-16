
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a={9,11,13,14,16};
    cout<<upper_bound(a.begin(),a.end(),8)-a.begin()<<endl;
    cout<<upper_bound(a.begin(),a.end(),15)-a.begin();
}