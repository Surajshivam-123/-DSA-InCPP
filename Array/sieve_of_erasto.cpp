#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    
    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            // marking as false
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}


vector<vector<int>> find_primefactor(int N){
    vector<vector<int>>prime_fac(N+1);
    for(int i=2;i<=N;i++){
        if(!prime_fac[i].empty())
            continue;
        for(int j=i;j<=N;j+=i){
            prime_fac[j].push_back(i);
        }
    }
    return prime_fac;
}
int main(){
    int n = 35;
    vector<vector<int>> res = find_primefactor(n);
    for(auto ele : res){
        for(int i=0;i<ele.size();i++){
            cout<<ele[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}