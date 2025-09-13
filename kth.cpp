#include <iostream>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];  
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pi = partition(arr, left, right);

        if (pi == k) return arr[pi];                
        else if (pi > k) return quickSelect(arr, left, pi - 1, k); 
        else return quickSelect(arr, pi + 1, right, k);           
    }
    return -1;
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    int result = quickSelect(arr, 0, n - 1, k - 1); 

    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
