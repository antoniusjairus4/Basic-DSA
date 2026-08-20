#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        cout << "Invalid input";
        return 0;
    }

    priority_queue <int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int cost = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    cout << cost;
}