#include<iostream>
#include<vector>
using namespace std;
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
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
    