#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* card = (int*)calloc(n, sizeof(int));
    int* dp = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    dp[0] = card[0];
    for (int i = 1; i < n; i++) {
        int x = dp[i - 1] + card[0];
        int y = card[i];
        for (int j = 0; j <= ceil(i / 2); j++) {
            int tmp = dp[i - j - 1] + dp[j];
            if (y > tmp) {
                y = tmp;
            }
        }
        if (x < y) {
            dp[i] = x;
        }
        else {
            dp[i] = y;
        }
    }

    cout << dp[n - 1];

    return 0;
}