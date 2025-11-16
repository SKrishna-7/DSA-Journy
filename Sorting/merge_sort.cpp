#include<iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;      // Start of the first subarray (left...mid)
    int j = mid + 1;   // Start of the second subarray (mid+1...right)

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int left, int right) {
    
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2; // Prevents potential overflow

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void mergeSort(vector<int> &arr) {
    int n = arr.size();
    if (n > 0) {
        mergeSort(arr, 0, n - 1);
    }
}


int main() {
    vector<int> arr = {8, 9, 5, 3, 6, 1, 2};
    
    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    
    mergeSort(arr);
 
    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}