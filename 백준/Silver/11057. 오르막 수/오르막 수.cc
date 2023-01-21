#include <iostream>
#define MOD 10007

using namespace std;

int main() {
    int n;
    cin >> n;

    int** dp = new int *[n];

    for (int i = 0; i < n; i++) {
        dp[i] = new int[11];
        for (int j = 0; j < 10; j++) {
            dp[0][j] = 1;
        }
    }
    dp[0][10] = 10;

    int sum = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][10] % MOD;
        sum = dp[i][0] % MOD;
        for (int j = 1; j < 10; j++) {
            int num = (dp[i][j - 1] % MOD - dp[i - 1][j - 1] % MOD) % MOD;
            if (num < 0) {
                num += MOD;
            }
            dp[i][j] = num;
            sum += num;
        }
        dp[i][10] = sum % MOD;
    }
    
    cout << dp[n - 1][10] % MOD;

    for (int i = 0; i < n; i++) {
        delete dp[i];
    }
    return 0;
}