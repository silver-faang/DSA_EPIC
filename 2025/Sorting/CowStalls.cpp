#include <bits/stdc++.h>
using namespace std;

#define ll long long
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main()
{
    fastio();
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto chk = [&](int md) -> bool
    {
        int c = 1, p = v[0];
        for (int i = 1; i < n; i++)
        {
            if (v[i] - p >= md)
            {
                c++;
                p = v[i];
            }
            if (c == m)
                return true;
        }
        return false;
    };

    int l = 0, h = v[n - 1] - v[0];
    int ans;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        // cout<<l<<" l  h "<<h<<endl;
        if (chk(md))
        {
            // cout<<md<<" mdYES\n";
            ans= md;
            l=md+1;
        }
        else
        {
            h = md - 1;
            // cout<<md<<" mdNO\n";
        }
    }
    cout << ans << endl;
    return 0;
}