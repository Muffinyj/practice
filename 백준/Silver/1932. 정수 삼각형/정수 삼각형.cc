#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int size = (1 + n) * n / 2;
    int* dp = new int[size];
    int* num = new int[size];
    memset(dp, 0, n * sizeof(int));

    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }

    dp[0] = num[0];
    for (int i = 1; i < n; i++) {
        int start = (1 + i) * i / 2;
        int end = start + i;
        for (int j = start; j < end; j++) {
            int x = num[j] + dp[j - i];
            int y = num[j + 1] + dp[j - i];
            if (x > dp[j]) {
                dp[j] = x;
            }
            if (y > dp[j + 1]) {
                dp[j + 1] = y;
            }
        }
    }

    sort(dp, dp + size);

    cout << dp[size - 1];

    delete[] dp;
    return 0;
}