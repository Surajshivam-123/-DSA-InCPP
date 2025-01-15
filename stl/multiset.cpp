#include<iostream>
#include<set>
using namespace std;
int main(){
    multiset<int>ms={1,2,9,3,5,3,8,5};
    ms.insert(23);
    //Arranged in ascending order//Duplication allowed
    for(int i:ms){
        cout<<i<<endl;
    }
}