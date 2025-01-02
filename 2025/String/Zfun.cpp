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

    string s;
    cin >> s;

    vector<int> Z = computeZFunction(s);

    // Output Z-values from index 1 to n-1
    for (int i = 1; i < Z.size(); ++i) {
        if (i > 1) cout << " ";
        cout << Z[i];
    }
    cout << endl;

    return 0;
}
