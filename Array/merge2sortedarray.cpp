#include<iostream>
using namespace std;
void  merge2sortarray(int a[],int m,int b[],int n){
        int j=m-1,k=n-1;
        while(j>=0 && k>=0){
            if(a[j]>=b[k]){
                a[j+k+1]=a[j];
                j--;
            }
            else {
                a[j+k+1]=b[k];
                k--;
            }
        }
            
                while(k>=0){
                    a[k]=b[k];
                    k--;
                }

        }

int main(){
    int a[]={4,5,6,0,0,0};
    int m=3;
    int b[]={1,2,3};
    int n=3;
    merge2sortarray(a,3,b,3);
    for(int i=0;i<m+n;i++){
        cout<<a[i]<<endl;
    }
    
}