#include<iostream>
#include<vector>
using namespace std;
/*
You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
*/
bool isvalid(int mid,int m,vector<int>book){//Time complexityO(n)
        int pages=0;
        int st=1;
        for(int i=0;i<book.size();i++){
            if(book[i]>mid){
                return 0 ;
            }
            if(pages+book[i]<=mid){
                pages+=book[i];
            }
            else{
                st++;
                pages=book[i];
            }
        }
        if(st<=m){
            return 1;
        }
        else
            return 0;
}

int allocatebooks(vector<int>arr,int m){//Time complexity n*logn
    if(m>arr.size()){
        return -1;//Not possible
    }
    int sum=0;
    for(int val:arr){
        sum+=val;
    }
    int st=0,end=sum,ans=-1;//range of possible ans
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(mid,m,arr)){//left
            ans=mid;
            end=mid-1;
        }
        else//right
            st=mid+1;
    }
    return ans;
}
int main(){
vector<int>book={15,17,20};
int m=2;
cout<<allocatebooks(book,m)<<endl;
return 0;
}