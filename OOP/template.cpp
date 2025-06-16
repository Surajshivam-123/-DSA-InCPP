#include<iostream>
using namespace std;

template<class T>
T findMax(T a,T b){
    return a>=b?a:b;
}
int main()
{
    cout<<findMax<int>(5,6)<<endl;
    cout<<findMax<int>('k','l')<<endl;
    cout<<findMax("Suraj","Shivam")<<endl;
    cout<<findMax<int>(50,62)<<endl;
return 0;
}