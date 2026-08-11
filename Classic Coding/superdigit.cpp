#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n < 0){
        cout << "Invalid";
        return 0;
    }

    int super_digit = (n - 1) % 9 + 1;

    cout << super_digit << endl;
}