#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009

vector<bool> is_prime(1000, true);
vector<int> primes;

// Function to precompute all 3-digit primes

void precompute_primes() {
    int c=0;
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    for (int i = 2; i * i < 1000; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < 1000; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 100; i < 1000; ++i) {
        if (is_prime[i]) {
            c++;
            primes.push_back(i);
        }
    }
    cout<<c<<"ans\n";
}


int count_special_numbers(int N) {
    // Initialize DP table
    vector<vector<int>> dp(N + 1, vector<int>(100, 0));

    // Base case: position 3, initialize with valid 3-digit primes
    for (int prime : primes) {
        int last_two = prime % 100;
        dp[3][last_two] = (dp[3][last_two] + 1) % MOD;
    }

    
    // DP transitions
    for (int pos = 4; pos <= N; ++pos) {
    vector<int> new_dp(100, 0);
    for (int last_two = 10; last_two < 100; ++last_two) {
        if (dp[pos - 1][last_two] > 0) {
            for (int d = 0; d <= 9; ++d) {
                int new_number = last_two * 10 + d;
                if (is_prime[new_number]) {
                    new_dp[new_number % 100] = 
                        (new_dp[new_number % 100] + dp[pos - 1][last_two]) % MOD;
                }
            }
        }
    }
    dp[pos] = new_dp;
}

    
    // Sum up results for position N
    int result = 0;
    for (int last_two = 10; last_two < 100; ++last_two) {
        result = (result + dp[N][last_two]) % MOD;
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    precompute_primes();
    cout << count_special_numbers(N) << endl;

    return 0;
}
