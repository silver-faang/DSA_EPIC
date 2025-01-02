#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    set<ll> s;
    ll last_result = 0; // Store the last result of a query

    for (int i = 0; i < n; ++i) {
        char op;
        ll value;
        cin >> op >> value;

        if (op == '+') {
            // Adjust the value based on the last query result if the previous operation was a query
            if (last_result != 0) {
                value = (value + last_result) % MOD;
                last_result = 0; // Reset the last result after adjustment
            }
            s.insert(value);
        } else if (op == '?') {
            // Find the smallest element in the set that is not less than the given value
            auto it = s.lower_bound(value);
            if (it == s.end()) {
                cout << -1 << "\n";
                last_result = -1;
            } else {
                cout << *it << "\n";
                last_result = *it;
            }
        }
    }

    return 0;
}
