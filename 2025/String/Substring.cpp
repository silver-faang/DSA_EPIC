#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7; 
const ll BASE = 31;     

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void compute_hashes(const string& s, vector<ll>& prefix_hash, vector<ll>& power) {
    int n = s.size();
    prefix_hash.resize(n + 1, 0);
    power.resize(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        prefix_hash[i] = (prefix_hash[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % MOD;
        power[i] = (power[i - 1] * BASE) % MOD;
    }
}

ll get_hash(int a, int b, const vector<ll>& prefix_hash, const vector<ll>& power) {
    ll hash_value = (prefix_hash[b] - prefix_hash[a - 1] * power[b - a + 1] % MOD + MOD) % MOD;
    return hash_value;
}

int main() {
    fastio();

    string s;
    cin >> s;
    int m;
    cin >> m;

    vector<ll> prefix_hash, power;
    compute_hashes(s, prefix_hash, power);
    while (m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;


        if ((b - a) == (d - c) && get_hash(a, b, prefix_hash, power) == get_hash(c, d, prefix_hash, power)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
