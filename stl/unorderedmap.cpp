#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>um;
    //duplcation not allowed
    um["Don"]=50;//Allowed
    um.emplace("Don",60);//Not added
    um.insert({"Lion",50});
    um["Pak"]=00;
    um["ind"]=200;
    um["Sneha"]=1008;
    for(auto p:um){
        cout<<p.first<<" "<<p.second<<endl;
    }
    //Output is not in any order
}