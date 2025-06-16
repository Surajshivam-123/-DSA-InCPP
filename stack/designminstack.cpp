#include<iostream>
using namespace std;
class Minstack{
    int minval;
    stack<int>s;
    public:
    int getmin(){
        return minval;
    }
    void push(int val){
        if(s.empty()){
            s.push(val);
            minval=val;
        }
        if(val<minval){
            s.push(2*val-minval);//We convert two thing into combination to reduce space complexity
            minval=val;
        }
        else{
            s.push(val);
        }
    }
    void pop(){
        if(minval<s.top()){//after combining resultant will become less than minval
            minval=2*val-s.top();//we restore previous value of min
        }
        s.pop();
    }
    int top(){
        if(minval<s.top()){
            return minval;
        }
        return  s.top();
    }

};
int main()
{
return 0;
}