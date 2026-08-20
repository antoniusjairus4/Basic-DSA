#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int knapsack(const vector<int>& wt, const vector<int>& val, int n, int c) {
    vector<vector<int>> dp(n, vector<int>(c + 1, 0));

    for (int i = wt[0]; i <= c; i++) {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int w = 0; w <= c; w++) {
            int not_take = dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w) {
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            }
            dp[ind][w] = max(take, not_take);
        }
    }

    return dp[n - 1][c];
}

int main() {
    vector<int> wt = {3, 4, 5};
    vector<int> val = {30, 50, 60};
    int n = wt.size();
    int c = 8;

    int max_val = knapsack(wt, val, n, c);

    return 0;
}