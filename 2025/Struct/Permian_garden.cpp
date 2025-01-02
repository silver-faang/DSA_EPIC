#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Plant
{
    double x, y;
    ll idx;
};

vector<double> calculateSquareSizes(ll W, ll H, vector<Plant> &plants)
{
    ll N = plants.size();
    vector<double> result(N, LLONG_MAX);

    vector<Plant> sortedByX = plants;
    sort(sortedByX.begin(), sortedByX.end(), [](const Plant &a, const Plant &b)
         { return a.x < b.x; });
    vector<Plant> sortedByY = plants;
    sort(sortedByY.begin(), sortedByY.end(), [](const Plant &a, const Plant &b)
         { return a.y < b.y; });

    for (ll i = 0; i < N; ++i)
    {
        double x = plants[i].x, y = plants[i].y, idx = plants[i].idx;
        double leftDist = 2 * x, rightDist = 2 * (W - x);
        double topDist = 2 * (H - y), bottomDist = 2 * (y);

        // Find nearest neighbors on the left and right
        auto itX = lower_bound(sortedByX.begin(), sortedByX.end(), plants[i], [](const Plant &a, const Plant &b)
                               { return a.x < b.x; });

        while (itX != sortedByX.begin() && prev(itX)->x < x)
        {
            --itX;
            leftDist = min(leftDist, x - itX->x);
        }
        // Iterate for right neighbors
        itX = lower_bound(sortedByX.begin(), sortedByX.end(), plants[i], [](const Plant &a, const Plant &b)
                          { return a.x < b.x; });
        while (next(itX) != sortedByX.end() && next(itX)->x > x)
        {
            ++itX;
            rightDist = min(rightDist, itX->x - x);
        }
        // Find nearest neighbors on the top and bottom
        auto itY = lower_bound(sortedByY.begin(), sortedByY.end(), plants[i], [](const Plant &a, const Plant &b)
                               { return a.y < b.y; }); // Iterate for bottom neighbors
        while (itY != sortedByY.begin() && prev(itY)->y < y)
        {
            --itY;
            bottomDist = min(bottomDist, y - itY->y);
        }
        // Iterate for top neighbors
        itY = lower_bound(sortedByY.begin(), sortedByY.end(), plants[i], [](const Plant &a, const Plant &b)
                          { return a.y < b.y; });
        while (next(itY) != sortedByY.end() && next(itY)->y > y)
        {
            ++itY;
            topDist = min(topDist, next(itY)->y - y);
        }
        cout << leftDist << " " << rightDist << " " << topDist << " " << bottomDist << " " << idx << "\n";
        double minSize = min({leftDist, rightDist, topDist, bottomDist});
        result[idx] = minSize;
    }

    return result;
}

int main()
{
    ll W, H, N;
    cin >> W >> H >> N;

    vector<Plant> plants(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> plants[i].x >> plants[i].y;
        plants[i].idx = i;
    }

    vector<double> result = calculateSquareSizes(W, H, plants);

    for (double size : result)
    {
        cout << size << "\n";
    }

    return 0;
}
