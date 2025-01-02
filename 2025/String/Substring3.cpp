#include <bits/stdc++.h>
using namespace std;

vector<int> buildSuffixArray(const string &s) {
    int n = s.size(), classes = 256;
    vector<int> sa(n), c(n), cnt(max(n, classes), 0);
    for (int i = 0; i < n; ++i) cnt[s[i]]++;
    for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) sa[--cnt[s[i]]] = i;
    c[sa[0]] = 0;
    classes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[sa[i]] != s[sa[i - 1]]) classes++;
        c[sa[i]] = classes - 1;
    }
    vector<int> sa2(n), c2(n);
    for (int len = 1; len < n; len <<= 1) {
        iota(sa2.begin(), sa2.end(), 0);
        for (int i = 0; i < n; ++i) {
            int s1 = sa[i] - len;
            if (s1 >= 0) sa2[cnt[c[s1]]++] = s1;
        }
        c2[sa2[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; ++i) {
            int mid1 = (sa2[i] + len) % n, mid2 = (sa2[i - 1] + len) % n;
            if (c[sa2[i]] != c[sa2[i - 1]] || c[mid1] != c[mid2]) classes++;
            c2[sa2[i]] = classes - 1;
        }
        sa.swap(sa2);
        c.swap(c2);
    }
    return sa;
}

vector<int> buildLCP(const string &s, const vector<int> &sa) {
    int n = s.size(), h = 0;
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (rank[i] > 0) {
            int j = sa[rank[i] - 1];
            while (i + h < n && j + h < n && s[i + h] == s[j + h]) h++;
            lcp[rank[i]] = h;
            if (h > 0) h--;
        }
    }
    return lcp;
}

string longestCommonSubstring(const vector<string> &strs) {
    string combined;
    vector<int> lengths, sa, lcp;
    int k = strs.size();
    for (const auto &str : strs) {
        combined += str + '#'; //
        lengths.push_back(str.size());
    }
    combined.pop_back(); //delimiter

    sa = buildSuffixArray(combined);
    lcp = buildLCP(combined, sa);

    int n = combined.size(), max_len = 0, start_idx = -1;
    for (int i = 1; i < n; ++i) {
        set<int> origins;
        for (int j = i - 1; j <= i; ++j) {
            int idx = sa[j];
            int original_string = 0, pos = idx;
            for (; original_string < k; ++original_string) {
                if (pos < lengths[original_string]) break;
                pos -= lengths[original_string] + 1;
            }
            origins.insert(original_string);
        }
        if (origins.size() == k && lcp[i] > max_len) {
            max_len = lcp[i];
            start_idx = sa[i];
        }
    }

    return combined.substr(start_idx, max_len);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> strs(k);
    for (int i = 0; i < k; ++i) cin >> strs[i];

    string result = longestCommonSubstring(strs);
    cout << result << endl;

    return 0;
}
