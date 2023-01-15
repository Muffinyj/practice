#include <iostream>
#include <cstdlib>
#include <cstring>
#define MOD 1000000000

using namespace std;

int main() {
    int n,sign(0);
    cin >> n;

    if (n > 0) {
        sign = 1;
    }
    else if (n < 0) {
        sign = -1;
        n = -n;
    }

    int* dp = (int*)calloc(n + 1, sizeof(int));

    dp[0] = 0;
    dp[1] = 1;

    if (sign > 0) {
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        cout << 1 << "\n" << dp[n] % MOD;
    }
    else if (sign < 0) {
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 2] - dp[i - 1]) % MOD;
        }
        if (n % 2 == 0) {
            cout << -1 << "\n" << -(dp[n] % MOD);
        }
        else {
            cout << 1 << "\n" << dp[n] % MOD;
        }
    }
    else {
        cout << 0 << "\n" << dp[n];
    }

    return 0;
}