#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* stair = (int*)calloc(n + 1, sizeof(int));
    int* dp = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }

    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[2] + dp[1];
    for (int i = 3; i <= n; i++) {
        int x = dp[i - 3] + stair[i - 1] + stair[i];
        int y = dp[i - 2] + stair[i];
        if (x > y) {
            dp[i] = x;
        }
        else {
            dp[i] = y;
        }
    }

    cout << dp[n];

    return 0;
}