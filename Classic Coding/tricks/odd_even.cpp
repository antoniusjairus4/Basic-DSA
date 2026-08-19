#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    if(!(cin >> n) || n < 0){
        cout << "Invalid input";
        return 0;
    }

    if(n & 1){
        cout << "Odd";
    }
    else{
        cout << "Even";
    }

    return 0;
}