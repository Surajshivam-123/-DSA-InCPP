#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//mat[i][j]->person i know j
//To become celebrity(celeb)->
// 1.celeb must not know any person(mat[celeb][i]==0)
// 2.every person must know celeb(mat[i][celeb]==1)
int celebrityroblem(vector<vector<int>>mat){
    int n=mat.size();
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }
    while(s.size()>1){//O(n)
        int i=s.top();s.pop();
        int j=s.top();s.pop();
        if(mat[i][j]==0){
            s.push(i);
        }
        else{
            s.push(j);
        }
    }
    int celeb=s.top();
    for(int i=0;i<n;i++){//O(n)
        if(i!=celeb &&(mat[i][celeb]==0 || mat[celeb][i]==1))
            return -1;
    }
    return celeb;
}
int main(){
vector<vector<int>>mat;
mat={{0,1,0},
    {0,0,0},
    {0,1,0}};
    cout<<celebrityroblem(mat)<<endl;
return 0;
}