#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int mincost = INT_MAX;

void tsp (vector <vector <int>> & cost, vector <bool> & visited, int currcity, int count, int currcost, int n)
{
    if(count == n){
        currcost += cost [currcity] [0];
        mincost = min (currcost, mincost);
        return;
    }

    for(int i = 0 ; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            tsp(cost, visited, i, count+1, currcost+cost [currcity] [i], n);
            visited[i] = false;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    if(n < 1){
        cout << "Invalid input";
        return 0;
    }

    vector <vector <int>> cost(n, vector<int>(n));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            cin >> cost[i][j];
            if(cost[i][j] < 0){
                cout<<"Invalid input";
                return 0;
            }
        }
    }

    vector <bool> visited (n, false);
    visited[0] = true;

    tsp(cost, visited, 0, 1, 0, n);
    cout << mincost;

}