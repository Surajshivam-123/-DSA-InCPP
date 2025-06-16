#include<iostream>
#include<cstring>
//#include<string>
using namespace std;
int main()
{
    char str[]="Hello World";
    //searching
    //cout<<*strchr(str,'p')<<endl;crash programme if does not exist
    //tokenization
    char delimeter[]=" ";
    char* token=strtok(str,delimeter);
    while(token!=nullptr){
        cout<<token<<endl;
        token=strtok(nullptr,delimeter);
    }
    //cpp string
    string s1="Shivam";
    string s2("Suraj");
    string s3(4,'X');
    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    cout<<s1.length()<<endl;
    cout<<s1+' '+s2<<endl;
    s1.append(s3);
    cout<<s1<<endl;
    cout<<s1[0]<<" "<<s1.at(1)<<endl;
    cout<<s1.substr(1,4)<<endl;//(startindeex,length)
    size_t pos=s2.find("raj");//returns index of r
    if(pos!=string::npos){
        cout<<pos<<endl;
}
    s2.replace(1,2,"hun");
    cout<<s2<<endl;
    s2.erase(1,2);
    cout<<s2<<endl;
    s2.insert(2,"ers");
    cout<<s2<<endl;
    s2.clear();
    cout<<s2<<endl;
    cout<<s2.empty()<<endl;
return 0;
}