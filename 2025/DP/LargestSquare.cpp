#include <bits/stdc++.h>
using namespace std;

void findLargestSquare(const vector<vector<int>>& matrix, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSize = 0, maxI = 0, maxJ = 0;

    // Fill the DP table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // Edge cases
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                if (dp[i][j] > maxSize) {
                    maxSize = dp[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }
        }
    }

    // Output the results
    cout << maxSize << endl;
    cout << maxI - maxSize + 2 << " " << maxJ - maxSize + 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    findLargestSquare(matrix, n, m);

    return 0;
}
