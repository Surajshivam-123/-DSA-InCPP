#include <iostream>
#include <vector>
using namespace std;
// print all divisor

vector<int> allDivisor(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (n / i != i)
            {
                ans.push_back(n / i);
            }
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return ans;
}

bool isPrime(int n)
{ // O((sqrt(n))
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// print all prime factor

vector<int> allPrimeFactor(int n)
{ // O(sqrt(n)*2*sqrt(n))
    if(n==2 || n==3)return {n};
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0 && isPrime(i))
        {
            ans.push_back(i);
            if (n / i != i && isPrime(n / i))
                ans.push_back(n / i);
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return ans;
}

// more optimized
vector<int> allPrimeFactor2(int n)
{ // O(sqrt(n)*log(n))
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
        ans.push_back(n);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return ans;
}

// power exponentian
int pow(int x, int n)
{
    int ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans *= x;
            n--;
        }
        else
        {
            n /= 2;
            x *= x;
        }
    }
    return ans;
}

// sieve of eratosthenes find all prime numbers till N

vector<int> allPrime(int n)//O(nlog(log(n))+n +n)
{
    vector<bool> prime(n + 1, true);
    vector<int> ans;
    for (int i = 2; i*i<=n; i++)
    {
        if (prime[i]){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
        
    }
    for(int i=2;i<=n;i++){
        if(prime[i])ans.push_back(i);
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return ans;
}

// smallest prime factor
int smallestPrimeFactor(int n)//O(nlog(log(n))+n +n)
{
    vector<int> prime(n + 1, INT_MAX);
    int ans;
    for (int i = 2; i*i<=n; i++)
    {
        if (prime[i]==INT_MAX){
            for(int j=i*i;j<=n;j+=i){
                prime[j] = min(prime[j],i);
            }
        }
        
    }
    ans=prime[n];
    cout << ans << "\n";
    return ans;
}
// Fast exponentiation
    long long power(long long base, long long exp){
        long long result = 1;
        while(exp > 0){
            if(exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
int main()
{

    allDivisor(21);
    cout << isPrime(7) << endl;
    allPrimeFactor(35);
    allPrimeFactor2(35);
    cout << pow(4, 10) << endl;
    allPrime(35);
    smallestPrimeFactor(35);
    return 0;
}


