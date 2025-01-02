#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const string& str1, const string& str2) {
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dp[i][j] = min({
                dp[i - 1][j] + 1,      // Delete
                dp[i][j - 1] + 1,      // Insert
                dp[i - 1][j - 1] + cost // Subs
            });

            if (i > 1 && j > 1 && str1[i - 1] == str2[j - 2] && str1[i - 2] == str2[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + cost); // Transp
            }
        }
    }

    return dp[n][m];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << solve(str1, str2) << "\n";
    return 0;
}