#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* num = (int*)calloc(n, sizeof(n));
    int* dp = (int*)calloc(n, sizeof(n));

    for (int i = 0; i < n; i++) {
        cin >> num[i];
        dp[i] = num[i];
    }

    dp[0] = num[0];
    for (int i = 1; i < n; i++) {
        int tmp = dp[i];
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                if (dp[j] + dp[i] > tmp) {
                    tmp = dp[j] + dp[i];
                }
            }
        }
        dp[i] = tmp;
    }

    sort(dp, dp + n);

    cout << dp[n - 1];

    return 0;
}