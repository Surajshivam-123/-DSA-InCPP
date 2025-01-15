#include<bits/stdc++.h>
using namespace std;
void ratmaze(vector<vector<bool>>&vis,string p,vector<string>&path,vector<vector<int>>maze,int r,int c,int n){
    if(r<0 ||c<0 || r>=n || c>=n || maze[r][c]==0 || vis[r][c]==true){
        return;
    }
    if(r==n-1 && c==n-1){
        path.push_back(p);
        return;
    }
    vis[r][c]=true;//visit
    ratmaze(vis,p+'U',path,maze,r-1,c,n);//Up
    ratmaze(vis,p+'D',path,maze,r+1,c,n);//down
    ratmaze(vis,p+'L',path,maze,r,c-1,n);//left
    ratmaze(vis,p+'R',path,maze,r,c+1,n);//right
    vis[r][c]=false;//unvisit
}
//Without using visited vector
//Tc-O(4()number of calls at each r and c)^(n**2(number of elements in maze)))
void ratmaze2(string p,vector<string>&path,vector<vector<int>>&maze,int r,int c,int n){
    if(r<0 ||c<0 || r>=n || c>=n || maze[r][c]==0){
        return;
    }
    if(r==n-1 && c==n-1){
        path.push_back(p);
        return;
    }
    maze[r][c]=0;//visited
    ratmaze2(p+'U',path,maze,r-1,c,n);//Up
    ratmaze2(p+'D',path,maze,r+1,c,n);//down
    ratmaze2(p+'L',path,maze,r,c-1,n);//left
    ratmaze2(p+'R',path,maze,r,c+1,n);//right
    maze[r][c]=1;//unvisited
}
int main(){
    vector<vector<int>>maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>path;
    string p;
    vector<vector<bool>>vis(4,vector<bool>(4,false));
    ratmaze2(p,path,maze,0,0,4);
   for(auto v:path){
    cout<<v<<endl;
   }
}