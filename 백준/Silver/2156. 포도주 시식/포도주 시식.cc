#include <iostream>
#include <vector>

using namespace std;

int _max(int x, int y, int z) {
    return x > y ? (x > z ? x : z) : (y > z ? y : z);
}

int main() {
    int n;
    cin >> n;

    int* wine = new int[n];
    int* dp = new int[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> wine[i];
    }

    dp[0] = 0;
    dp[1] = wine[0];
    dp[2] = dp[1] + wine[1];

    for (int i = 3; i <= n; i++) {
        dp[i] = _max(dp[i - 1], dp[i - 2] + wine[i - 1], dp[i - 3] + wine[i - 2] + wine[i - 1]);
    }

    cout << dp[n];

    return 0;
}