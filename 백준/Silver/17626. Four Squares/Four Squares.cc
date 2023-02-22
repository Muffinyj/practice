#include <iostream>
#include <cstring>

using namespace std;

void getCount(int *dp, int num) {
    for (int i = 1; i * i <= num; i++) {
        if (!dp[num]) {
            dp[num] = dp[i * i] + dp[num - i * i];
        }
        else {
            if (dp[num] > dp[i * i] + dp[num - i * i]) {
                dp[num] = dp[i * i] + dp[num - i * i];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* dp = new int[n + 1];
    int cnt = 0;

    memset(dp, 0, sizeof(int)*(n + 1));

    for (int i = 1; i * i <= n; i++) {
        dp[i*i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!dp[i]) {
            getCount(dp, i);
        }
    }

    cout << dp[n];

    return 0;
}