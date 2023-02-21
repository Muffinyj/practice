#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double* f = new double[n];
    double* dp = new double[n];

    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    dp[0] = f[0];
    double max = 0;
    for (int i = 1; i < n; i++) {
        if (f[i] > dp[i - 1] * f[i]) {
            dp[i] = f[i];
        }
        else {
            dp[i] = dp[i - 1] * f[i];
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    printf("%0.3f", max);

    return 0;
}