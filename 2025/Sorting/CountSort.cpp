#include <iostream>
#include <vector>
using namespace std;
 
void countingSort(vector<int>& arr) {
    int n = arr.size();
    int maxElement = 1e5;
    vector<int> count(maxElement + 1, 0);
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= maxElement; ++i) {
        count[i] += count[i - 1];
    }
    vector<int> result(n);
    for (int i = n - 1; i >= 0; --i) {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    arr = result;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i += 1)
        cin >> arr[i];
    countingSort(arr);
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
    return 0;
}