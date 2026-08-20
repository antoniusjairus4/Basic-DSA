#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

using namespace std;

int coin_change(vector<int>& coins, int n) {
    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int k : coins) {
            if (i - k >= 0) {
                dp[i] = min(dp[i], dp[i - k] + 1);
            }
        }
    }

    return dp[n] > n ? -1 : dp[n];
}

int main() {
    vector<int> coins = {1, 2, 3, 5};
    int n = 15;
    
    int res = coin_change(coins, n);
    
    cout << res << endl;

    return 0;
}