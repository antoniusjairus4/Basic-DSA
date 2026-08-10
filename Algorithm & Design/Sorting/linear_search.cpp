#include <iostream>
#include <string>

using namespace std;

int linear_search(int n, int target, int arr[]) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int n;
    if (!(cin >> n) || n <= 0) {
        cout << "Enter a valid positive input." << endl;
    }

    int target;
    cin >> target;

    
    int arr[n]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = linear_search(n, target, arr);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}