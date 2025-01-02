#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 9;
const vector<int> primes = {101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
                             151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

int countSpecialNumbers(int N) {
    vector<vector<int>> dp(N + 1, vector<int>(10, 0));
    
    // Initialize dp for 1-digit numbers
    for (int j = 0; j <= 9; ++j) {
        dp[1][j] = 1;
    }

    // Iterate through digits from 2 to N
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            // Check if adding digit j forms a prime number with the last two digits
            for (int k = 0; k <= 9; ++k) {
                int num = k * 100 + j * 10;
                num += primes[k] % 10;
                if (num >= 100 && num <= 999) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    // Count the total number of special numbers of length N
    int total = 0;
    for (int j = 1; j <= 9; ++j) {
        total = (total + dp[N][j]) % MOD;
    }

    return total;
}

int main() {
    int N;
    cin >> N;
    cout << countSpecialNumbers(N) << endl;
    return 0;
}
