#include<iostream>
using namespace std;
//In every operation everything becomes 0 after 1st bit from right 
int main(){
    int c=0;
    int x=19;
    while(x!=0){
        x=x & x-1;
        c++;
    }
    cout<<c<<endl;
}