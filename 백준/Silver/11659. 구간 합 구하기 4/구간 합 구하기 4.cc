#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int* dp = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        cout << dp[b] - dp[a - 1] << "\n";
    }

    return 0;
}