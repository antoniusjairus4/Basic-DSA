#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 10; 

int main() {
    int n;
    if (!(cin >> n) || n <= 0 || n > MAX_N) {
        return 1;
    }

    int cost[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int assigned_tasks[MAX_N];
    for (int i = 0; i < n; i++) {
        assigned_tasks[i] = i;
    }

    int min_cost = INT_MAX;
    int best_assignment[MAX_N];

    do {
        int current_cost = 0;
        
        for (int i = 0; i < n; i++) {
            current_cost += cost[i][assigned_tasks[i]];
        }

        if (current_cost < min_cost) {
            min_cost = current_cost;
            for (int i = 0; i < n; i++) {
                best_assignment[i] = assigned_tasks[i];
            }
        }
    } while (next_permutation(assigned_tasks, assigned_tasks + n));

    cout << min_cost;
    
    return 0;
}