#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next, jumps;
};

vector<int> launchStrength;
vector<Node> info;

void preprocess(int n) {
    info.resize(n + 1);
    for (int i = n; i >= 1; --i) {
        if (i + launchStrength[i] > n) {
            info[i] = {i, 1};  // Exit directly
        } else {
            info[i] = {info[i + launchStrength[i]].next, info[i + launchStrength[i]].jumps + 1};
        }
    }
}

void update(int n, int idx, int value) {
    launchStrength[idx] = value;
    for (int i = idx; i >= 1; --i) {
        if (i + launchStrength[i] > n) {
            info[i] = {i, 1};
        } else {
            auto nextInfo = info[i + launchStrength[i]];
            if (info[i].next == nextInfo.next && info[i].jumps == nextInfo.jumps + 1) {
                break;  // No further updates needed
            }
            info[i] = {nextInfo.next, nextInfo.jumps + 1};
        }
    }
}

pair<int, int> throwBall(int startPos) {
    int pos = startPos, jumps = 0;
    while (pos <= launchStrength.size() && info[pos].next != pos) {
        jumps += info[pos].jumps;
        pos = info[pos].next;
    }
    return {pos, jumps};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    launchStrength.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> launchStrength[i];
    }

    preprocess(N);

    while (M--) {
        int type, a, b;
        cin >> type;
        if (type == 0) {
            cin >> a >> b;
            update(N, a, b);
        } else if (type == 1) {
            cin >> a;
            auto result = throwBall(a);
            cout << result.first << " " << result.second << "\n";
        }
    }

    return 0;
}
