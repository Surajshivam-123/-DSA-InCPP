#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s={5,5,8,2,4,0,10,1};
    //Duplicate are not allowed
    //Automatically arranged in ascending order
    s.insert(13);
    cout<<s.erase(100)<<endl;//returns 1 if present otherwise returns 0;
    cout<<*s.lower_bound(4)<<endl;//just greater than or equal to 4
    cout<<*s.upper_bound(4)<<endl;//just grater than 4
    cout<<*s.upper_bound(13)<<endl;//Unexpected results
    cout<<*s.lower_bound(14)<<endl;
    
    // set<int>::iterator it;
    // for(auto it=s.begin();it!=s.end();it++){
    //     cout<<*it<<endl;
    // }
    for(int e:s){
        cout<<e<<endl;
    }
    // for(int i=0;i<s.size();i++){//Not allowed
    //     cout<<s[i]<<endl;
    // }

}