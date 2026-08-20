#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    getline(cin, text);
    int n = text.length();

    string pattern;
    getline(cin, pattern);
    int m = pattern.length();

    if (m > n) {
        return 0;
    }

    for (int i = 0; i <= n - m; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            cout << "Pattern found at index: " << i << "\n";
        }
    }

    return 0;
}