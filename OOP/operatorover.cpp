#include<iostream>
using namespace std;
//Overloading of []operator
const int limit=100;
class safearray{
    int a[limit];
    public:
    safearray(){
        for(int i=0;i<limit;i++){
            a[i]=rand()%10;
        }
    }
    int operator[](int n){
        if(n<0 || n>=limit){
            cout<<"Out of Bound Error"<<endl;
            return -1;
        }
        else{
            return a[n];
        }

    }
};
int main(){
    safearray A;
    for(int i=0;i<limit;i++){
        cout<<A[i]<<" ";
    }
return 0;
}