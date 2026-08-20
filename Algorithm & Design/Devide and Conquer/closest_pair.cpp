#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_N = 100;

int main()
{
    int n;
    if (!(cin >> n) || n <= 1 || n > MAX_N) {
        return 1;
    }

    double x[MAX_N];
    double y[MAX_N];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double d_min = 1e9;
    int a = -1, b = -1;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            double d = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            
            if (d < d_min) {
                d_min = d;
                a = i;
                b = j;
            }
        }
    }
    
    cout << fixed << setprecision(4);
    cout << "Closest pair indices: Point " << a << " and Point " << b << "\n";
    cout << "Minimum distance : " << d_min << "\n";

    return 0;
}