#include <iostream>
#include <cstdlib>
#include <cstring>
#define MIN -100000001

using namespace std;

int main() {
    int n;
    cin >> n;

    int* num = (int*)calloc(n, sizeof(int));
    int* dp = (int*)calloc(n, sizeof(int));
    memset(dp, MIN, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    dp[0] = num[0];
    int max = dp[0];
    for (int i = 1; i < n; i++) {
        if (num[i] < num[i] + dp[i - 1]) {
            dp[i] = num[i] + dp[i - 1];
        }
        else {
            dp[i] = num[i];
        }
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    cout << max;

    return 0;
}