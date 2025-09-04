#include<iostream>
#include<vector>
using namespace std;
vector<int> countSort(vector<int>a){ //TC->O(maxelement+n)
    //find max ele;
    int maxele=0;
    for(int i=0;i<a.size();i++){
        maxele=max(maxele,a[i]);
    }
    //make array of size maxele+1 and assign 0 to each index
    vector<int>countArr(maxele+1,0);
    for(int i=0;i<a.size();i++){
        countArr[a[i]]++;
    }
    int in=0;
    for(int i=0;i<countArr.size();i++){
        while(countArr[i]!=0){
           a[in++]=i;
           countArr[i]--;
        }
    }
    return a;
}
int main(){
    vector<int>arr={5,6,1,8,9,2,3,1,5};
    arr=countSort(arr);
    for(int v:arr){
        cout<<v<<" ";
    }
    cout<<endl;
return 0;
}