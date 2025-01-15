#include<iostream>
using namespace std;
void unique(int ar[],int sz){
    int c;
    for(int i=0;i<sz;i++){
        c=0;
        for(int j=0;j<sz;j++){
            if(ar[i]==ar[j]){
                c++;
            }
        }
        if(c==1){
            cout<<ar[i]<<endl;
        }
    
    }
}

int main(){
int suraj[5]={1,2,3,2,1};
unique(suraj,5);
return 0;
}