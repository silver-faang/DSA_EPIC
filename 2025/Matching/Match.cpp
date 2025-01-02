#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250;
vector<int> adj[MAXN + 1];
vector<int> level;
vector<int> pairU, pairV;
vector<bool> visitedU, visitedV;

bool bfs(int n) {
    queue<int> q;
    for (int u = 1; u <= n; ++u) {
        if (pairU[u] == 0) {
            level[u] = 0;
            q.push(u);
        } else {
            level[u] = INT_MAX;
        }
    }
    level[0] = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (level[u] < level[0]) {
            for (int v : adj[u]) {
                if (level[pairV[v]] == INT_MAX) {
                    level[pairV[v]] = level[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }
    return (level[0] != INT_MAX);
}

bool dfs(int u) {
    if (u != 0) {
        for (int v : adj[u]) {
            if (level[pairV[v]] == level[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        level[u] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp(int n, int m) {
    pairU.assign(n + 1, 0);
    pairV.assign(m + 1, 0);
    level.assign(n + 1, 0);

    int matching = 0;
    while (bfs(n)) {
        for (int u = 1; u <= n; ++u) {
            if (pairU[u] == 0 && dfs(u)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int u = 1; u <= n; ++u) {
        while (true) {
            int v;
            cin >> v;
            if (v == 0) break;
            adj[u].push_back(v);
        }
    }

    int max_matching = hopcroftKarp(n, m);
    cout << max_matching << "\n";
    for (int u = 1; u <= n; ++u) {
        if (pairU[u] != 0) {
            cout << u << " " << pairU[u] << "\n";
        }
    }

    return 0;
}
