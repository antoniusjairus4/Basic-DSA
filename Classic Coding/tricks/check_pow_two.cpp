#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isPower = (n > 0) && ((n & (n - 1)) == 0);

    cout << isPower;
}