#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    int **dp = new int*[n + 1];
    int **human = new int*[2];
    const int max_weight = 100;

    for (int i = 0; i < 2; i++) {
        human[i] = new int[n + 1];
        for (int j = 1; j <= n; j++) {
            cin >> human[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        dp[i] = new int[max_weight];
    }

    for (int i = 0; i <= n; i++) {
        memset(dp[i], 0, sizeof(int) * max_weight);
    }

    for (int i = 1; i <= n; i++) {
        int w = human[0][i];
        int v = human[1][i];
        for (int j = 1; j < max_weight; j++) {
            if (j - w >= 0) {
                if (dp[i - 1][j] >= dp[i - 1][j - w] + v) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j - w] + v;
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][99];

    return 0;
}