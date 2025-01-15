#include <iostream>
#include <list>
using namespace std;
int main() {
   list<int>l={3,7,1,9,15,67};
   //List cannot be randomly access
   list<int>::iterator it;
   for(it=l.begin();it!=l.end();it++){
      cout<<*it<<endl;
   }
advance(it,3);
cout<<*it<<endl;
//New thing
l.push_front(5);
l.pop_front();
}