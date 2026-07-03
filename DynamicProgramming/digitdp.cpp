// https://leetcode.com/problems/count-good-integers-in-a-range/
class Solution {
    vector<vector<vector<long long>>>dp;
    long long get(int i,int prev,bool small,int k,int n,string &s){
        if(i==n)return 1;
        if(dp[i][prev][small]!=-1)return dp[i][prev][small];
        long long ans=0;
        int start=max(0,prev-k);
        int end=min(9,prev+k);
        if(!small)end=min(end,(int)(s[i]-'0'));
        for(int j=start;j<=end;j++){
            ans+=get(i+1,j,small or j<(s[i]-'0'),k,n,s);
        }
        return dp[i][prev][small]=ans;
    }
    long long f(long long num,int k){
        dp.assign(16,vector<vector<long long>>(10,vector<long long>(2,-1)));
        string s=to_string(num);
        int n=s.length();
        long long ans=0;
        for(int i=0;i<n;i++){
            int end=(i==0)?s[0]-'0':9;
            for(int prev=1;prev<=end;prev++){
                if(i==0 && prev==end){
                    ans+=get(i+1,prev,false,k,n,s);
                }
                else{
                    ans+=get(i+1,prev,true,k,n,s);
                }

            }
        }
        return ans;
    }
public:
    long long goodIntegers(long long l, long long r, int k) {
        return f(r,k)-f(l-1,k);
    }
};