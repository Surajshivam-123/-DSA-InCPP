#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>don;
    cout<<"1 element is added"<<endl;
    don.push_back(4);
    cout<<"size="<<don.size()<<endl;
    cout<<"capacity="<<don.capacity()<<endl;
    cout<<"2 element is added"<<endl;
    don.push_back(5);
    cout<<"size="<<don.size()<<endl;
    cout<<"capacity="<<don.capacity()<<endl;
    cout<<"3 element is added"<<endl;
    don.push_back(6);
    cout<<"size="<<don.size()<<endl;
    cout<<"capacity="<<don.capacity()<<endl;
    cout<<"4 element is added"<<endl;
    don.push_back(7);
    cout<<"size="<<don.size()<<endl;
    cout<<"capacity="<<don.capacity()<<endl;
    cout<<"5 element is added"<<endl;
    don.push_back(8);
    cout<<"size="<<don.size()<<endl;
    cout<<"capacity="<<don.capacity()<<endl;


return 0;
}