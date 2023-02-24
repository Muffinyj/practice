#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int** dp = new int* [k];

    for (int i = 0; i < k; i++) {
        dp[i] = new int[n + 1];
    }
    for (int i = 0; i < k; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j < k; j++) {
            dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % 1000000000;
        }
    }

    cout << dp[k - 1][n];

    return 0;
}