#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    if(!(cin >> n) || n < 0){
        cout << "Invalid input";
        return 0;
    }

    char arr[n];

    for(int i = 0; i < n; i++){
        if(!(cin >> arr[i]) || (isdigit(arr[i]))){
            cout << "Invalid input";
            return 0;
        }    
    }

    char ch;
    if(!(cin >> ch)){
        cout << "Invalid input";
        return 0;
    }

    bool found = false;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == ch){
            cout << i << " ";
            found = true;
        }
    }

    if(!found){
        cout << "Not Found";
    }

    return 0;
}