#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<pair<int, int>> stones(N);
    for (int i = 0; i < N; ++i) {
        cin >> stones[i].first >> stones[i].second;
    }

    long long weightDifference = 0;
    int maxWeightPan1 = -1, maxWeightPan2 = -1;
    int countPan1 = 0, countPan2 = 0;

    for (const auto& stone : stones) {
        int R = stone.first;
        int S = stone.second;

        if (S == 1) {
            weightDifference += R;
            maxWeightPan1 = max(maxWeightPan1, R);
            countPan1++;
        } else {
            weightDifference -= R;
            maxWeightPan2 = max(maxWeightPan2, R);
            countPan2++;
        }

        if (weightDifference < 0 && countPan1 <= countPan2) {
            cout << "<\n";
        } else if (weightDifference > 0 && countPan1 >= countPan2) {
            cout << ">\n";
        } else {
            cout << "?\n";
        }
    }

    return 0;
}
