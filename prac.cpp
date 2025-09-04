#include<iostream>
#include<map>
using namespace std;
int main(){
   map<string,int>m;
   m["suraj"]=1;
   m["shivam"]=2;
   for(auto it:m){
      cout<<it.first<<" "<<it.second<<endl;
   }
}
