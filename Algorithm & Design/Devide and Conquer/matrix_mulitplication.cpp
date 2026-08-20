#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n + 1);

    for(int i = 0; i <= n; i++){
        cin >> arr[i];
    }

    vector <vector <int>> dp(n + 1, vector<int> (n + 1, 0));

    for(int len = 2; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){

            int j = i + len - 1;
            
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];

                dp[i][j]=min(dp[i][j], cost);
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }

    return 0;
}