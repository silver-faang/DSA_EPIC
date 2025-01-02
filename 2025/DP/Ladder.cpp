#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    dp[0][0] = 1;

    for (int n = 0; n <= N; ++n) {
        for (int k = 1; k <= N; ++k) {
            dp[n][k] = dp[n][k-1];
            if (n >= k) {
                dp[n][k] += dp[n-k][k-1];
            }
        }
    }

    cout << dp[N][N] << endl;

    return 0;
}
