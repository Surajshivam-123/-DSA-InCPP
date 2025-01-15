#include<iostream>
using namespace std;
int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
//Mam's approach
int maximumsubarraysum(int arr[],int n){
    int maxsum=INT16_MIN;
    for(int st=0;st<n;st++){
        int sum=0;
        for(int end=st;end<n;end++){
            sum+=arr[end];
            maxsum=max(sum,maxsum);
        }
        
        }
        return maxsum;
}
//My approach
int main(){
    int array[]={3,-4,5,4,-1,7,-8};
    int n=7;
    int sum,b=INT16_MIN;
    for(int st=0;st<n;st++){
        for(int end=0;end<n;end++){
            sum=0;
            for(int i=st;i<=end;i++){
                sum+=array[i];
            }
            if(sum>b){
                b=sum;
            }
        }
    }
    cout<<b<<endl;
    cout<<maximumsubarraysum(array,n);

}