#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Helper function to multiply two 2x2 matrices
vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    vector<vector<long long>> C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

// Function to perform modular matrix exponentiation: (A^p) % MOD
vector<vector<long long>> power(vector<vector<long long>> A, long long p) {
    // Initialize identity matrix
    vector<vector<long long>> res = {{1, 0}, {0, 1}};
    
    while (p > 0) {
        if (p & 1) { // If p is odd
            res = multiply(res, A);
        }
        A = multiply(A, A); // Square the matrix
        p >>= 1;            // Divide p by 2
    }
    return res;
}

// Function to return the n-th Fibonacci number
long long getFibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Transformation matrix M
    vector<vector<long long>> M = {{1, 1}, {1, 0}};

    // Raise M to the power of (n - 1)
    M = power(M, n - 1);

    // F_n is the top-left element of M * [F_1, F_0]^T
    // Since F_1 = 1 and F_0 = 0, F_n is simply M[0][0]
    return M[0][0];
}

int main() {
    long long n;
    cout << "Enter n: ";
    if (cin >> n) {
        cout << "Fibonacci(" << n << ") % (10^9 + 7) = " << getFibonacci(n) << endl;
    }
    return 0;
}