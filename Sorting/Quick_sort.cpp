#include <iostream>
#include <vector>
using namespace std;

long long medianOfThree(vector<long long> &arr, long long low, long long high) {
    long long mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) {
        swap(arr[low], arr[mid]);
    }

    if (arr[low] > arr[high]) {
        swap(arr[low], arr[high]);
    }

    if (arr[mid] > arr[high]) {
        swap(arr[mid], arr[high]);
    }

    return mid;
}

long long partition(vector<long long> &arr, long long low, long long high) {
    long long pivotIndex = medianOfThree(arr, low, high);
    swap(arr[pivotIndex], arr[high]);

    long long pivot = arr[high];
    long long i = low - 1;

    for (long long j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<long long> &arr, long long low, long long high) {
    if (low < high) {
        long long pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i += 1)
        cin >> arr[i];
    quickSort(arr, 0, arr.size() - 1);
    for (long long num : arr)
        cout << num << " ";
    cout << "\n";
    return 0;
}
