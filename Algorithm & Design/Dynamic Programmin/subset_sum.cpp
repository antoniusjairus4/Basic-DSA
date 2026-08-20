#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {2, 3, 5};
    int n = arr.size();
    int B = 8;

    vector<vector<bool>> dp(n + 1, vector<bool>(B + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= B; j++) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    cout << dp[n][B];

    return 0;
}