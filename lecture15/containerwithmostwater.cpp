#include<iostream>
#include<vector>
using namespace std;
//bruteforce approach
int maxAreab(vector<int>& height) {
        int area,maxarea;
        for(int i=1;i<=height.size();i++){
            for(int j=i;j<=height.size();j++){
                area=(j-i)*min(height[j-1],height[i-1]);
                maxarea=max(area,maxarea);
            }
        }
        return maxarea;
    }
    //using 2 pointer approach
int maxAreao(vector<int>& height){
    int lp=0,rp=height.size()-1;
    int w,h,area,maxarea;
    while(lp<rp){
        w=rp-lp;
        h=min(height[lp],height[rp]);
        area=w*h;
        maxarea=max(area,maxarea);
        height[lp]>height[rp]?rp--:lp++;
    }
    return maxarea;
}
    int main(){

    }
    