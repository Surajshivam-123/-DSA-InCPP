// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

// Example 1:

// Input: n = 3, l = 4, r = 5

// Output: 2

// Explanation:

// There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

// [4, 5, 4]
// [5, 4, 5]
// Example 2:

// Input: n = 3, l = 1, r = 3

// Output: 10

// Explanation:

// ​​​​​​​There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

// [1, 2, 1], [1, 3, 1], [1, 3, 2]
// [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
// [3, 1, 2], [3, 1, 3], [3, 2, 3]
#define ll long long int
#define mod 1000000007
class Solution {
public:

    vector<vector<ll>> multiply(vector<vector<ll>>& A, vector<vector<ll>>& B) {
        int n = A.size();

        vector<vector<ll>> C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) 
        {
            for (int k = 0; k < n; k++) 
            {
                if (A[i][k] == 0) 
                {
                    continue;
                }

                for (int j = 0; j < n; j++) {

                    if (B[k][j] == 0)
                    {
                        continue;
                    }
                    C[i][j] =(C[i][j]%mod + (A[i][k]%mod * B[k][j]%mod)%mod)%mod;
                }
            }
        }

        return C;
    }

    vector<vector<ll>> power(vector<vector<ll>> base, long long exp) {
        int n = base.size();

        vector<vector<ll>> result(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++)
        {
            result[i][i] = 1;
        }

        while (exp) 
        {
            if (exp & 1)
            {
                result = multiply(result, base);
            }
            base = multiply(base, base);
            exp >>=1;
        }

        return result;
    }
    
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        auto U = [&](int v) {
            return v - 1;
        };

        auto D = [&](int v) {
            return m + (v - 1);
        };

        vector<vector<ll>> T(S, vector<ll>(S, 0));

        for (int v = 1; v <= m; v++) 
        {
            for (int u = 1; u < v; u++) 
            {
                T[U(v)][D(u)] = 1;
            }
            for (int u = v + 1; u <= m; u++) 
            {
                T[D(v)][U(u)] = 1;
            }
        }

        vector<ll> dp2(S, 0);

        for (int v = 1; v <= m; v++) {
            dp2[U(v)] = v - 1;
            dp2[D(v)] = m - v;
        }

        vector<vector<ll>> P = power(T, n - 2);

        std::vector<long long> dpn(S, 0);

        for (int i = 0; i < S; i++) 
        {
            for (int j = 0; j < S; j++) 
            {
                dpn[i] = (dpn[i] + P[i][j] * dp2[j]) % mod;
            }
        }

        long long ans = 0;

        for (long long x : dpn)
        {
            ans = (ans + x) % mod;
        }

        return ans;
    }
};