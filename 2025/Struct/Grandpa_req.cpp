#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left, right, maxZero, size;
    Node() : left(0), right(0), maxZero(0), size(0) {}
};

class SegmentTree {
    vector<Node> tree;
    int n;

    void build(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node].size = 1;
            if (arr[start] == 0) {
                tree[node].left = tree[node].right = tree[node].maxZero = 1;
            }
            return;
        }
        int mid = (start + end) / 2;
        build(arr, start, mid, 2 * node + 1);
        build(arr, mid + 1, end, 2 * node + 2);
        merge(node, start, mid, end);
    }

    void merge(int node, int start, int mid, int end) {
        tree[node].size = (end - start + 1);
        tree[node].left = tree[2 * node + 1].left;
        tree[node].right = tree[2 * node + 2].right;
        tree[node].maxZero = max(tree[2 * node + 1].maxZero, tree[2 * node + 2].maxZero);

        if (tree[2 * node + 1].left == tree[2 * node + 1].size) {
            tree[node].left = tree[2 * node + 1].size + tree[2 * node + 2].left;
        }
        if (tree[2 * node + 2].right == tree[2 * node + 2].size) {
            tree[node].right = tree[2 * node + 2].size + tree[2 * node + 1].right;
        }
        tree[node].maxZero = max(tree[node].maxZero, tree[2 * node + 1].right + tree[2 * node + 2].left);
    }

    void update(int start, int end, int idx, int value, int node) {
        if (start == end) {
            if (value == 0) {
                tree[node].left = tree[node].right = tree[node].maxZero = 1;
            } else {
                tree[node].left = tree[node].right = tree[node].maxZero = 0;
            }
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(start, mid, idx, value, 2 * node + 1);
        } else {
            update(mid + 1, end, idx, value, 2 * node + 2);
        }
        merge(node, start, mid, end);
    }

    Node query(int start, int end, int l, int r, int node) {
        if (start > r || end < l) return Node();
        if (start >= l && end <= r) return tree[node];
        int mid = (start + end) / 2;
        Node left = query(start, mid, l, r, 2 * node + 1);
        Node right = query(mid + 1, end, l, r, 2 * node + 2);
        Node result;
        result.size = left.size + right.size;
        result.left = left.left;
        result.right = right.right;
        result.maxZero = max(left.maxZero, right.maxZero);
        if (left.left == left.size) {
            result.left = left.size + right.left;
        }
        if (right.right == right.size) {
            result.right = right.size + left.right;
        }
        result.maxZero = max(result.maxZero, left.right + right.left);
        return result;
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, n - 1, 0);
    }

    void update(int idx, int value) {
        update(0, n - 1, idx, value, 0);
    }

    int query(int l, int r) {
        Node res = query(0, n - 1, l, r, 0);
        return res.maxZero;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "UPDATE") {
            segTree.update(a - 1, b);
        } else if (op == "QUERY") {
            cout << segTree.query(a - 1, b - 1) << "\n";
        }
    }

    return 0;
}
