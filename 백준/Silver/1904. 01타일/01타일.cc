#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* dp = (int*)calloc(n + 1, sizeof(int));

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }

    cout << dp[n] % 15746;

    return 0;
}