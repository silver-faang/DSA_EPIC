#include <bits/stdc++.h>
using namespace std;

void generate_sequence(vector<int>& sequence, int n, int a1, int k, int b, int m) {
    sequence[0] = a1;
    for (int i = 1; i < n; ++i) {
        sequence[i] = (k * sequence[i - 1] + b) % m;
    }
}

vector<int> lis(const vector<int>& sequence) {
    vector<int> dp;
    vector<int> idx(sequence.size());
    vector<int> prev(sequence.size(), -1);
    int len = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), sequence[i]);
        int pos = distance(dp.begin(), it);
        if (it == dp.end()) {
            dp.push_back(sequence[i]);
        } else {
            *it = sequence[i];
        }
        idx[pos] = i;
        if (pos > 0) {
            prev[i] = idx[pos - 1];
        }
        if (pos == dp.size() - 1) {
            len = pos;
        }
    }
    vector<int> lis;
    for (int i = idx[len]; i >= 0; i = prev[i]) {
        lis.push_back(sequence[i]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;

    vector<int> sequence(n);
    generate_sequence(sequence, n, a1, k, b, m);

    vector<int> longest_increasing_subsequence = lis(sequence);

    cout << longest_increasing_subsequence.size() << endl;
    for (int num : longest_increasing_subsequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
