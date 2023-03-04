#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* dp = new int[n + 1];
    int* seq = new int[n + 1];

    dp[1] = 0;
    seq[1] = 0;
    dp[2] = 1;
    seq[2] = 1;
    dp[3] = 1;
    seq[3] = 1;

    int cnt = 1;
    for (int i = 4; i <= n; i++) {
        int x[3] = { dp[i - 1] + 1, INT_MAX, INT_MAX };
        if (i % 2 == 0) {
            x[1] = dp[i / 2] + 1;
        }
        if (i % 3 == 0) {
            x[2] = dp[i / 3] + 1;
        }

        if (x[0] < x[1]) {
            if (x[0] < x[2]) {
                dp[i] = x[0];
                seq[i] = i - 1;
            }
            else {
                dp[i] = x[2];
                seq[i] = i / 3;
            }
        }
        else {
            if (x[1] < x[2]) {
                dp[i] = x[1];
                seq[i] = i / 2;
            }
            else {
                dp[i] = x[2];
                seq[i] = i / 3;
            }
        }
    }

    cout << dp[n] << "\n";

    int num = n;
    cout << n << " ";
    while (seq[num] != 0) {
        cout << seq[num] << " ";
        num = seq[num];
    }

    return 0;
}