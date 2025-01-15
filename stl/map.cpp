#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>mp;
    mp["Suraj"]=100;
    mp["Shivam"]=200;
    mp["Shubham"]=300;
    mp.insert({"Tannu",400});
    mp.emplace("Ayush",500);
    mp.emplace("Shivam",300);//Not added//Two same key value pair does not exist
    mp.erase("Shivam");
    //To find value of particular key
    map<string,int>::iterator it=mp.find("Suraj");
    if(it!=mp.end()){
        cout<<it->first<<endl;//if no key found nothing will print
        cout<<it->second<<endl;
    }
    cout<<mp.count("Suraj")<<endl;
    for(auto p:mp){
        cout<<p.first<<" "<<p.second<<endl;
    }
    //Keys are arranged according to lexicographical order in ascending order
    
}