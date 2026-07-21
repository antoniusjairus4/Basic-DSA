#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int swaps = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    swaps++;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    if(n < 0) {
        cout << "Invalid input";
        return 0;
    }

    int* arr = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i != n - 1) cout << " ";
    }

    cout << endl;
    cout << swaps;

    delete[] arr;

    return 0;
}