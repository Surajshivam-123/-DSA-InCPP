/*In this question we have to find maximum number of element lies just back of current which is smaller than current value
For example:-If given array is [100,80,60,70,60,75,85] then answer would be [1 1 1 2 1 4 6]*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int>giv={100,80,60,70,60,75,85};
    vector<int>ans(7);
    stack<int>s;
    int in=0;
    for(int i=0;i<giv.size();++i){
        while(s.size()>0 && giv[s.top()]<=giv[i]){
            s.pop();
        }
        if(s.empty()){
            ans[in++]=i+1;
        }
        else{
            ans[in++]=i-s.top();
        }
        s.push(i);
    }
    for(int v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
}