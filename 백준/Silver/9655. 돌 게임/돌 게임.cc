#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* dp = (int*)calloc(n + 1, sizeof(int));

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        if (dp[i - 3] > dp[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = dp[i - 3] + 1;
        }
    }

    if (dp[n] % 2 == 0) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }

    return 0;
}