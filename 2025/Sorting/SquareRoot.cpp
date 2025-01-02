#include <bits/stdc++.h>
using namespace std;

#define ll long long
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

double calculate(double x) { return x * x + sqrt(x); }
int main()
{
    fastio();
    double C;
    cin >> C; 
    double low = 0, high =  C;
    double EPS = 1e-7;
    while (high - low > EPS)
    {
        double mid = (low + high) / 2.0;
        if (calculate(mid) < C)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    } 
    cout << fixed << setprecision(6) << low << endl;
    return 0;}