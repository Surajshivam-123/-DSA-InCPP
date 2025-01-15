#include<stdio.h>
void re(int a[],int b[],int n1,int n2){
    int c[n1+n2];
    int n1p=0,n2p=0,in=0;
    while(n1p!=n1 || n2p!=n2){
        if(a[n1p]==b[n2p]){
            c[in++]=a[n1p];
            n1p++;n2p++;
        }
        else if(a[n1p]<b[n2p] && n1p<n1){
            c[in++]=a[n1p];
            n1p++;
        }
        else if(a[n1p]>b[n2p] && n2p<n2){
            c[in++]=b[n2p];
            n2p++;
        }
    }
    for(int i=0;i<in;i++){
        printf("%d",c[i]);
    }
}
int main(){
    int x[]={2,3,5,7};
    int y[]={5,8,11,12};
    re(x,y,4,4);
}