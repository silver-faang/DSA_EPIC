#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    // Build adjacency list and calculate degree
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // Sort adjacency lists by degree for faster common neighbor search
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    int triangleCount = 0;

    // Count triangles
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            if (v > u) {  // Process edge (u, v) only once
                // Use two-pointer approach to find common neighbors
                auto it1 = adj[u].begin();
                auto it2 = adj[v].begin();
                while (it1 != adj[u].end() && it2 != adj[v].end()) {
                    if (*it1 == *it2) {
                        if (*it1 > v) {  // Ensure triangle is counted correctly
                            triangleCount++;
                        }
                        ++it1;
                        ++it2;
                    } else if (*it1 < *it2) {
                        ++it1;
                    } else {
                        ++it2;
                    }
                }
            }
        }
    }

    cout << triangleCount << "\n";
    return 0;
}
