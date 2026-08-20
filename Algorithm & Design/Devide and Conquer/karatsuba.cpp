#include <bits/stdc++.h>

using namespace std;

long long karatsuba(long long x, long long y){

    if (x < 10 || y < 10) {
        return x * y;
    }

    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;

    long long power = (long long)pow(10, m);

    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long z0 = karatsuba(b, d);
    long long z2 = karatsuba(a, c);
    long long z1 = karatsuba(a + b, c + d);

    return z2 * (long long)pow(10, 2 * m) + (z1 - z2 - z0) * power + z0;
}

int main() {
    long long x, y;

    if (cin >> x >> y) {
        long long result = karatsuba(x, y);
        cout << "Product: " << result << "\n";
    }

    return 0;
}