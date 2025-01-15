#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>us={1,7,2,2,6,3,5,9,18,4};
    //Duplication not allowed
    //Present in any order
    for(int p:us){
        cout<<p<<endl;
    }
}