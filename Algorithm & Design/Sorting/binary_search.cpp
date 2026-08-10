#include <iostream>
#include <string>

using namespace std;

int binary_search(int arr[], int target, int n){
    int low = 0;
    int high = n - 1;

    while(low <= high){
        int mid = low + (high + low) / 2;

        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] < target){
            low = mid + 1;
        }

        else{
            high = mid - 1;
        }

        return -1;
    }
}

int main()
{
    int n;
    if(!(cin >> n) || n < 0){
        cout << "Enter a valid number";
    }

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int result = binary_search(arr, target, n);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } 
    else {
        cout << "Element not found in the array." << endl;
    }
    
    return 0;
}