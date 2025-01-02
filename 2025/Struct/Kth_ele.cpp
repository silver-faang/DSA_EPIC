#include <bits/stdc++.h>
using namespace std;
#define ll long long

#pragma GCC optimize("O3") 

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int start, int end, int index, int pos, int val) {
        if (start == end) {
            tree[index] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid) {
            update(start, mid, 2 * index + 1, pos, val);
        } else {
            update(mid + 1, end, 2 * index + 2, pos, val);
        }
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }

    int findKth(int start, int end, int index, int k) {
        if (start == end) {
            return start;
        }
        int mid = (start + end) / 2;
        if (tree[2 * index + 2] >= k) {
            return findKth(mid + 1, end, 2 * index + 2, k);
        } else {
            return findKth(start, mid, 2 * index + 1, k - tree[2 * index + 2]);
        }
    }
};

int main() {
    fastio();

    int n;
    cin >> n;

    vector<pair<int, ll>> commands;
    set<ll> all_values;

    for (int i = 0; i < n; ++i) {
        int command;
        ll value;
        cin >> command >> value;
        commands.emplace_back(command, value);

        if (command != 0) {
            all_values.insert(value);
        }
    }

    // Coord
    unordered_map<ll, int> compress;
    int index = 0;
    for (const ll value : all_values) {
        compress[value] = ++index;
    }

    SegmentTree segTree(index);

    for (const auto& cmd : commands) {
        int command = cmd.first;
        ll value = cmd.second;

        if (command == 1) {
            segTree.update(1, index, 0, compress[value], 1);
        } else if (command == -1) {
            segTree.update(1, index, 0, compress[value], -1);
        } else if (command == 0) {
            int k = value;
            int resultIndex = segTree.findKth(1, index, 0, k);
            for (const auto& pair : compress) {
                if (pair.second == resultIndex) {
                    cout << pair.first << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
