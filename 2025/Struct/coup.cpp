#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
public:
    vector<int> tree, lazy;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);  // lazy array to track flip
    }

    // Build the tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    // Propagate the lazy flip
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] = -tree[node];  // Flip the current segment

            if (start != end) {
                lazy[2 * node] ^= 1;  // Mark left child for flip
                lazy[2 * node + 1] ^= 1;  // Mark right child for flip
            }

            lazy[node] = 0;  // Reset the lazy flag
        }
    }

    // Update a range [l, r] by flipping
    void update(int node, int start, int end, int l, int r) {
        propagate(node, start, end);  // Propagate any previous lazy updates

        if (r < start || end < l) return;  // Out of range
        if (l <= start && end <= r) {
            lazy[node] ^= 1;  // Flip this segment
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r);
        update(2 * node + 1, mid + 1, end, l, r);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    // Query the minimum value in range [l, r]
    int query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);  // Propagate any pending updates

        if (r < start || end < l) return INT_MAX;  // Out of range
        if (l <= start && end <= r) return tree[node];  // Current segment fully in range

        int mid = (start + end) / 2;
        int left_query = query(2 * node, start, mid, l, r);
        int right_query = query(2 * node + 1, mid + 1, end, l, r);
        return min(left_query, right_query);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    SegmentTree segTree(n);
    segTree.build(arr, 1, 1, n);

    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            segTree.update(1, 1, n, l, r);  // Flip the range
        } else {
            cout << segTree.query(1, 1, n, l, r) << endl;  // Query the minimum in the range
        }
    }

    return 0;
}
