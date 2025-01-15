#include<iostream>
using namespace std;
int facto(int x){
    if(x==0 || x==1){
        return 1;
    }
    return x*facto(x-1);
}
int main(){
    cout<<facto(5)<<endl;
}