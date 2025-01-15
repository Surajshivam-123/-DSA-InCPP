#include<iostream>
using namespace std;
void printnum(int x){
    if(x==1){
        cout<<"1\n";
        return;
    }
    
    printnum(x-1);
    cout<<x<<endl;
}
int main(){
    printnum(9);
}