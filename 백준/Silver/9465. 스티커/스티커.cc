#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int sticker[2][100002];
int dp[2][100002];

void getValue(int num) {

    for (int i = 2; i <= num; i++) {
        if (dp[1][i - 2] > dp[1][i - 1]) {
            dp[0][i] = sticker[0][i] + dp[1][i - 2];
        }
        else {
            dp[0][i] = sticker[0][i] + dp[1][i - 1];
        }

        if (dp[0][i - 2] > dp[0][i - 1]) {
            dp[1][i] = sticker[1][i] + dp[0][i - 2];
        }
        else {
            dp[1][i] = sticker[1][i] + dp[0][i - 1];
        }
    }

    return;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        int m = 0;
        cin >> num;

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= num; j++) {
                cin >> sticker[i][j];
            }
        }

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        getValue(num);

        if (dp[0][num] > dp[1][num]) {
            cout << dp[0][num];
        }
        else {
            cout << dp[1][num];
        }

        cout << "\n";
    }

    return 0;
}