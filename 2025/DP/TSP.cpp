#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = INT_MAX;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastio();

    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    int N = 1 << n; 
    vector<vector<int>> dp(N, vector<int>(n, INF));
    vector<vector<int>> parent(N, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < N; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { 
                for (int j = 0; j < n; ++j) {
                    if (!(mask & (1 << j))) { 
                        int next_mask = mask | (1 << j);
                        if (dp[mask][i] + cost[i][j] < dp[next_mask][j]) {
                            dp[next_mask][j] = dp[mask][i] + cost[i][j];
                            parent[next_mask][j] = i;
                        }
                    }
                }
            }
        }
    }

    int min_cost = INF;
    int last_vertex = -1;
    for (int i = 0; i < n; ++i) {
        if (dp[N - 1][i] < min_cost) {
            min_cost = dp[N - 1][i];
            last_vertex = i;
        }
    }

    vector<int> path;
    int mask = N - 1;
    while (last_vertex != -1) {
        path.push_back(last_vertex + 1);
        int temp = last_vertex;
        last_vertex = parent[mask][last_vertex];
        mask ^= (1 << temp);
    }
    //reverse(path.begin(), path.end());

    cout << min_cost << endl;
    int m=path.size();
    for (int i = m-1; i >=0 ; i--) {
        cout << path[i]<<" ";
    }
    cout << endl;

    return 0;
}
