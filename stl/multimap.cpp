#include<iostream>
#include<map>
using namespace std;
int main(){
    multimap<string,int>mm;
    //We cannot add like mm["Swift"]=100;
    mm.emplace("Suraj",500);
    mm.emplace("Suraj",300);//Here added
    mm.emplace("Suraj",800);
    mm.emplace("Ankit",50);
    mm.emplace("Muskan",50);
    cout<<mm.count("Suraj")<<endl;
    //mm.erase("Suraj");//erase all key value pair havin "Suraj" as key
    //mm.erase(mm.find("Suraj"));//first key value pair having "Suraj" as key will be deleted
    for(auto p:mm){
        cout<<p.first<<" "<<p.second<<endl;
    }
    //Arranged in ascending order a/c to key
}