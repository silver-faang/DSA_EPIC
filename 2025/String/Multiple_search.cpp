#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 9; 
const ll BASE = 31;     

ll compute_hash(const string &s) {
    ll hash_value = 0;
    ll power = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return hash_value;
}

vector<ll> precompute_prefix_hashes(const string &t) {
    int n = t.size();
    vector<ll> prefix_hash(n + 1, 0); 
    ll power = 1;
    for (int i = 0; i < n; ++i) {
        prefix_hash[i + 1] = (prefix_hash[i] + (t[i] - 'a' + 1) * power) % MOD;
        power = (power * BASE) % MOD;
    }
    return prefix_hash;
}

ll substring_hash(const vector<ll> &prefix_hash, int l, int r) {
    ll hash_value = (prefix_hash[r + 1] - prefix_hash[l] + MOD) % MOD;
    return hash_value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    string t;
    cin >> t;

    vector<ll> prefix_hash = precompute_prefix_hashes(t);
    ll power = 1;
    for (int i = 0; i < t.size(); ++i) {
        power = (power * BASE) % MOD; // c BASE^(len(s_i)) % MOD
    }

    for (const auto &str : s) {
        int m = str.size();
        if (m > t.size()) {
            cout << "NO\n";
            continue;
        }


        ll hash_s = compute_hash(str);

        bool found = false;
        for (int i = 0; i + m - 1 < t.size(); ++i) {
            ll hash_t = substring_hash(prefix_hash, i, i + m - 1);

            if (hash_s == hash_t && t.substr(i, m) == str) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES" : "NO") << "\n";
    }

    return 0;
}
