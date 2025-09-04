#include<iostream>
using namespace std;
int linearsearch(int array[],int sz,int target){
    for(int i=0;i<sz;i++){
        if (array[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int shiv[]={1,2,3,4,5,6,7,8,9,0};
    int sz=10;
    cout<<linearsearch(shiv,sz,5);
    return 0;
    }
