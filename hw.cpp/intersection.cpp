#include<iostream>
using namespace std;
int intersection(int a[],int sa,int b[],int sb){
    for(int i=0;i<sa;i++){
        for(int j=0;j<sb;j++){
            if(a[i]==b[j]){
                cout<<a[i]<<endl;
            }
        }
    }
}
int main(){
int suraj[7]={1,2,3,4,5,6,7};
int shivam[7]={5,6,7,8,9,0};
intersection(suraj,7,shivam,7);
return 0;
}