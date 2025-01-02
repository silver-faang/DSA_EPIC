#include <bits/stdc++.h>
using namespace std;

vector<int> computeZFunction(const string& s) {
    int n = s.size();
    vector<int> Z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            ++Z[i];
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    string concat = s + "#" + t;
    vector<int> Z = computeZFunction(concat);

    int s_len = s.size();
    int t_len = t.size();
    int concat_len = concat.size();

    vector<int> occurrences;
    for (int i = s_len + 1; i < concat_len; ++i) {
        if (Z[i] == s_len) {
            occurrences.push_back(i - s_len); // 1-based index
        }
    }

    cout << occurrences.size() << endl;
    for (int i = 0; i < occurrences.size(); ++i) {
        cout << occurrences[i] << " ";
    }
    cout << endl;

    return 0;
}
