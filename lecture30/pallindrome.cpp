#include<iostream>
#include<string>
using namespace std;
bool ispallindrome(string str){
    int n=str.size();
    for(int i=0;i<=n/2;i++){
        if(str[i]!=str[n-i-1]){
            return 0;
        }

}
return 1;
}
 bool isPalindrome(string s) {
       int n=s.size();
       string s2;
       for(int i=0;i<n;i++){
        if(s[i]>=65 && s[i]<=90){
            s[i]=s[i]+32;
        }
       }
       int in=0;
       for(int i=0;i<n;i++){
        if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57) ){
            s2[in++]=s[i];
        }
       }
       n=s2.size();
       for(int i=0;i<=n/2;i++){
            if(s2[i]!=s2[n-i-1]) return 0;
       }
       return 1;
    }
int main(){
    string s="racecar";
    cout<<isPalindrome(s);
    string s2;
    //cout<<s<<endl;
    int n=s.size();
    for(int i=0;i<n;i++){
        s2[i]=s[n-i-1];
    }
    cout<<s2<<endl;
    return 0;
}