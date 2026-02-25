// The Skyline problem
// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

// The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

// lefti is the x coordinate of the left edge of the ith building.
// righti is the x coordinate of the right edge of the ith building.
// heighti is the height of the ith building.
// You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

// The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

// Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

 

// Example 1:


// Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
// Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
// Explanation:
// Figure A shows the buildings of the input.
// Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
// Example 2:

// Input: buildings = [[0,2,3],[2,5,3]]
// Output: [[0,3],[5,0]]

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>arr;
        for(auto it:buildings){
            arr.push_back({it[0],it[2],0});//0-start
            arr.push_back({it[1],it[2],1});//1-end
        }
        sort(arr.begin(),arr.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) return a[0] < b[0];

            // Same x-coordinate
            if (a[2] == 0 && b[2] == 0) return a[1] > b[1]; // start higher first
            if (a[2] == 1 && b[2] == 1) return a[1] < b[1]; // end lower first

            return a[2] < b[2]; // start before end
        });
        vector<vector<int>>ans;
        multiset<int>ms;
        ms.insert(0);
        for(auto it:arr){
            int mx=*ms.rbegin();
            if(it[2]==0){
                if(mx<it[1]){//if maximum will change after adding then push this into answer
                    ans.push_back({it[0],it[1]});
                }
                ms.insert(it[1]);
            }
            else{
                ms.erase(ms.find(it[1]));
                int dmx=*ms.rbegin();
                if(mx>dmx){//if maximum will change after removing this then push the current x axis with maximum
                    ans.push_back({it[0],dmx});
                }
            }
        }
        return ans;
    }
};


// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

 

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

int nthUglyNumber(int n) {
        vector<int>t(n+1,0);
        t[1]=1;
        int i2,i3,i5;
        i2=i3=i5=1;
        for(int i=2;i<=n;i++) {
            int f=t[i2]*2;
            int s=t[i3]*3;
            int th=t[i5]*5;
            t[i]=min({f,s,th});
            if(f==t[i]) i2++;
            if(s==t[i]) i3++;
            if(th==t[i]) i5++;
        }
        return t[n];
    }

// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
//  Example 1:

// Input
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// Output
// [null, null, null, 1.5, null, 2.0]

// Explanation
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        minheap.push(maxheap.top());
        maxheap.pop();
        if(maxheap.size()<minheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()!=maxheap.size())return maxheap.top();
        return (double)(maxheap.top()+minheap.top())/2;
    }
};


// Find K Pairs with Smallest Sums
// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);
        vector<vector<int>>ans;
        pq.push({0,0});
        while(ans.size()<k){
            auto [i,j]=pq.top();
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if((j+1)<nums2.size()){
                pq.push({i,j+1});
            }
            if(j==0 && i+1<nums1.size())
                pq.push({i+1,j});
        }
        return ans;
    }
};

// Kth Smallest Element in a Sorted Matrix
// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

 

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp=[&matrix](pair<int,int> a,pair<int,int> b){
            return matrix[a.first][a.second]>=matrix[b.first][b.second];
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);
        pq.push({0,0});
        while(!pq.empty() && k--){
            auto [i,j]=pq.top();
            pq.pop();
            if(k==0)return matrix[i][j];
            if(i+1<matrix.size()){
                pq.push({i+1,j});
            }
            if(i==0 && (j+1)<matrix[0].size()){
                pq.push({i,j+1});
            }
        }
        return -1;
    }
};

// Trapping Rainwater

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

// Example 1:


// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>boundaryCells;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        vector<vector<int>>dir={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<m;i++){
            for(int j:{0,n-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }
        }
        for(int j=0;j<n;j++){
            for(int i:{0,m-1}){
                boundaryCells.push({heightMap[i][j],{i,j}});
                visited[i][j]=true;
            }
        }
        int water=0;
        while(!boundaryCells.empty()){
            auto curr=boundaryCells.top();
            boundaryCells.pop();
            int height=curr.first;
            int i=curr.second.first;
            int j=curr.second.second;
            for(auto vec:dir){
                int newRow=i+vec[0];
                int newCol=j+vec[1];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !visited[newRow][newCol]){
                    water+=max(height-heightMap[newRow][newCol],0);
                    boundaryCells.push({max(height,heightMap[newRow][newCol]),{newRow,newCol}});
                    visited[newRow][newCol]=true;
                }
            }
        }
        return water;
    }
};

// TASK SCHEDULER
// You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

// Return the minimum number of CPU intervals required to complete all tasks.

 

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

// After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

// using heap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for(char t : tasks)
            freq[t]++;
        
        priority_queue<int> pq;
        for(auto it : freq)
            pq.push(it.second);
        
        queue<pair<int,int>> cooldown;
        
        int time = 0;
        
        while(!pq.empty() || !cooldown.empty()) {
            time++;
            
            if(!pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                
                if(cnt - 1 > 0)
                    cooldown.push({cnt - 1, time + n});
            }
            
            if(!cooldown.empty() && cooldown.front().second == time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        
        return time;
    }
};
// more optimal
int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int task:tasks){
            freq[task-'A']++;
        }
        int maxfreq=0;
        for(int i=0;i<26;i++){
            maxfreq=max(maxfreq,freq[i]);


        }
        int maxcount=0;
        for(int i=0;i<26;i++){
           if(maxfreq==freq[i]){
            maxcount++;
           }

        }
        return max((int)tasks.size(), ((maxfreq - 1) * (n + 1)) + maxcount);



    }