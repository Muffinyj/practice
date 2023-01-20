#include <iostream>
#define MAX 1000001

using namespace std;

int main() {
    int n;
    cin >> n;

    int* jump[3];
    int* dp[3];

    for (int i = 0; i < 3; i++) {
        jump[i] = new int[n];
        dp[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> jump[j][i];
            if (i > 0) {
                dp[j][i] = 0;
            }
            else {
                dp[j][i] = jump[j][i];
            }
        }
    }

    int min;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            min = MAX;
            for (int k = 0; k < 3; k++) {
                if (j != k && min > dp[k][i - 1]) {
                    min = dp[k][i - 1];
                }
            }
            dp[j][i] = min + jump[j][i];
        }
    }

    min = dp[0][n - 1];
    for (int i = 1; i < 3; i++) {
        if (min > dp[i][n - 1]) {
            min = dp[i][n - 1];
        }
    }

    cout << min;

    for (int i = 0; i < 3; i++) {
        delete dp[i];
        delete jump[i];
    }
    return 0;
}