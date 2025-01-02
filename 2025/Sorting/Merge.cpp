#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1,n2 = high - mid;
    vector<int> left(n1),right(n2);
    for (int i = 0; i < n1; ++i) {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; ++j) {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0,j = 0,k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < n1) {
        arr[k++] = left[i++];
    }
    while (j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i+=1) {
        cin>>arr[i];
    }
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    cout<<"\n";
    return 0;
}