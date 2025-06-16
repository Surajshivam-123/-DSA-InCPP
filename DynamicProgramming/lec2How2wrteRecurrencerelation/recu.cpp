#include<iostream>
using namespace std;
/*
How to find given question is solve by dp
-count the total number of ways
-find min and max of among all ways
-try all posssible ways

Three imp points
1.)Try to represent the problem in terms of index
2.)Do all possible stuffs on that acc to the problem statement
3.)sum of all stuffs->give output no. of ways
    min of all stuffs->find min
    */
/*Q.)we have stair and you can only climb once or twice step at once .You need to find total number of distinct ways to reach the top*/
int solve(int index){
    if(index==1 || index==0){
        return 1;
    }
    int left,right;
    left=solve(index-1);
    right=solve(index-2);
    return left +right;
}
int main(){
    cout<<solve(5)<<endl;
return 0;
}